#include <iostream>

using namespace std;

int item[101];       // 각 구역의 아이템 수 저장 배열
int route[101][101]; // 길의 길이 저장 배열
int INF = 10000000;  // 길 초기화 변수
int mx = 0;          // 최대 아이템 개수 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r, a, b, l;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            route[i][j] = INF; // 배열 초기화
    for (int i = 1; i <= n; i++)
        cin >> item[i]; // 아이템 수 저장
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        route[a][b] = l; // 직행 길 저장
        route[b][a] = l;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (route[i][k] + route[k][j] < route[i][j])
                    route[i][j] = route[i][k] + route[k][j]; // 경유 길 갱신
    for (int i = 1; i <= n; i++)
    {
        int sm = item[i]; // 해당 지역 아이템 개수 저장 변수
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue; // 제자리 노드 제외
            if (route[i][j] <= m)
                sm += item[j]; // 수색 범위 내 아이템 합산
        }
        if (mx < sm)
            mx = sm; // 최대 아이템 수 갱신
    }
    cout << mx;
    return 0;
}