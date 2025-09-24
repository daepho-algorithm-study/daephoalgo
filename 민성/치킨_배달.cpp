#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bt(int k, int cnt);    // 백트래킹 함수 정의
vector<pair<int, int>> chp; // 치킨집 위치 저장 배열
vector<pair<int, int>> p;   // 집 위치 저장 배열
vector<int> chm;            // M개의 치킨집 저장 배열
int chd[100];               // 치킨 거리 저장 배열
int m, mn = 1000000;        // 최소 치킨 거리 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num == 1) // 집 위치 저장
                p.push_back({i, j});
            else if (num == 2) // 치킨집 위치 저장
                chp.push_back({i, j});
        }
    bt(0, 0); // 백트래킹 실행
    cout << mn;
    return 0;
}

void bt(int k, int cnt)
{
    if (cnt == m) // M개의 치킨집 선택 완료 시
    {
        for (int i = 0; i < p.size(); i++)
            chd[i] = 10000; // 치킨 거리 배열 초기화
        for (int i = 0; i < chm.size(); i++)
        {
            int x = chp[chm[i]].first, y = chp[chm[i]].second; // 해당 치킨집 위치 할당
            for (int j = 0; j < p.size(); j++)
            {
                int a = p[j].first, b = p[j].second; // 해당 집 위치 할당
                int ch = abs(x - a) + abs(y - b);    // 치킨집과 집까지의 거리 계산
                if (ch < chd[j])
                    chd[j] = ch; // 치킨 거리 갱신
            }
        }
        int sm = 0; // 치킨 거리 합 저장 변수
        for (int i = 0; i < p.size(); i++)
            sm += chd[i];
        if (sm < mn)
            mn = sm; // 최소 치킨 거리 갱신
        return;
    }
    for (int i = k; i < chp.size(); i++)
    {
        chm.push_back(i);   // 해당 치킨집 선택
        bt(i + 1, cnt + 1); // 치킨집 선택 수 카운팅 후 재귀 깊이 +1
        chm.pop_back();     // bt 탐색 종류 후 해당 치킨집 제외
    }
}