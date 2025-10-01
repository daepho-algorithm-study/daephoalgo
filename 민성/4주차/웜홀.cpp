#include <iostream>
#include <vector>

using namespace std;

int cost[501];      // 최소시간 저장 배열
int cycle[501];     // 음의 사이클 체크 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, n, m, w, s, e, t;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        vector<vector<pair<int, int>>> load(501); // 각 지점의 도로 저장 배열
        cin >> n >> m >> w;
        for (int j = 1; j <= n; j++)
            cost[j] = 0; // 배열 초기화
        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            load[s].push_back({e, t}); // 도로 정보 저장
            load[e].push_back({s, t});
        }
        for (int j = 0; j < w; j++)
        {
            cin >> s >> e >> t;
            load[s].push_back({e, -t}); // 웜홀 정보 저장
        }
        for (int l = 0; l < n - 1; l++) // 노드 - 1번 반복
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k < load[j].size(); k++)
                {
                    // 도착점과 거리 저장
                    int nxt = load[j][k].first, d = load[j][k].second;
                    if (cost[nxt] > cost[j] + d)
                        cost[nxt] = cost[j] + d; // 최소시간 갱신
                }
            }
        for (int j = 1; j <= n; j++)
            cycle[j] = cost[j]; // 사이클 체크 전 최소시간 저장
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < load[j].size(); k++)
            {
                int nxt = load[j][k].first, d = load[j][k].second;
                if (cost[nxt] > cost[j] + d) // 한번 더 시간 갱신 시도
                    cost[nxt] = cost[j] + d;
            }
        }
        bool check = false; // 사이클 체크 변수
        for (int j = 1; j <= n; j++)
            if (cost[j] != cycle[j])
            {
                check = true;
                break;
            }
        if (check)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}