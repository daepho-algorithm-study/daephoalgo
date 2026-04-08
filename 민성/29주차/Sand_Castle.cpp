#include <iostream>
#include <algorithm>

using namespace std;

// 성벽 M과 B 저장 배열
int m[25000], b[25000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 총 비용 저장 변수 할당
    int n, x, y, sm = 0;
    cin >> n >> x >> y;
    // 성벽 정보 저장
    for (int i = 0; i < n; i++)
        cin >> m[i] >> b[i];
    // 성벽 정보 오름차순 정렬
    sort(m, m + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        // 부족한 만큼 쌓기
        if (m[i] < b[i])
            sm += (b[i] - m[i]) * x;
        // 초과한 만큼 낮추기
        else
            sm += (m[i] - b[i]) * y;
    }
    cout << sm;
    return 0;
}