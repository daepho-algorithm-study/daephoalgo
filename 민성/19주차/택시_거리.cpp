#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num, cnt = 0;
    // A, B 좌표 저장 변수
    pair<int, int> p[2];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            // 1일 때, 위치 저장
            if (num)
                p[cnt++] = {i, j};
        }
    // 거리 할당
    int d = abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second);
    cout << d;
    return 0;
}