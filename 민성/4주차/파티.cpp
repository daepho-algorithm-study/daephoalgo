#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int path(int a, int b);                    // 소요시간 계산 함수 정의
vector<vector<pair<int, int>>> load(1001); // 도로 소요시간 저장 배열
int cost[1001];                            // 최소시간 저장 배열
int n, INF = 10000000;                     // 초기화 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, x, s, e, t, mx = 0; // 최대시간 저장 변수
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        load[s].push_back({t, e}); // 각 도로의 도착점과 시간 저장
    }
    for (int i = 1; i <= n; i++)
    {
        int temp = path(i, x) + path(x, i); // 소요시간 계산
        if (mx < temp)
            mx = temp; // 최대값 갱신
    }
    cout << mx;
    return 0;
}

int path(int a, int b)
{
    fill(cost + 1, cost + n + 1, INF); // 배열 초기화
    priority_queue<pair<int, int>> pq; // 다익스트라를 위한 우선순위 큐 할당
    pq.push({0, a});                   // 초기값 할당
    cost[a] = 0;
    while (!pq.empty())
    {
        // 현재 위치와 누적 거리 할당
        int acc = -pq.top().first, cur = pq.top().second;
        pq.pop();
        if (cur == b)
            break; // 목적지 도착 시 반복문 종료
        for (int i = 0; i < load[cur].size(); i++)
        {
            // 다음 위치와 거리 할당
            int d = load[cur][i].first, nxt = load[cur][i].second;
            if (cost[nxt] > acc + d)
            {
                cost[nxt] = acc + d;        // 최소시간 갱신
                pq.push({-(acc + d), nxt}); // 다음 위치 탐색을 위해 큐에 삽입
            }
        }
    }
    return cost[b];
}