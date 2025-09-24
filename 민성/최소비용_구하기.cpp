#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> node(1001); // 노드들을 저장할 이차원 배열
priority_queue<pair<int, int>> pq;         // 다익스트라를 위한 우선순위 큐 할당
int mn[1001];                              // 최소비용을 체크하기 위한 배열
int INF = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, e, cost;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        mn[i] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> cost;
        node[s].push_back(make_pair(e, cost)); // 시작 노드 벡터에 종착지와 비용 저장
    }
    cin >> s >> e;
    pq.push(make_pair(0, s)); // 첫 시작 지점부터 우선순위 큐에 저장
    while (!pq.empty())
    {
        int acc = -pq.top().first, cur = pq.top().second; // 현재 탐색할 노드와 그 노드까지의 비용 할당
        if (cur == e)
            break; // 목적지까지 모두 갱신 했으면 반복문 종료
        pq.pop();
        for (int i = 0; i < node[cur].size(); i++)
        {
            int nxt = node[cur][i].first, cst = node[cur][i].second; // 다음 탐색 노드와 비용 할당
            if (mn[nxt] > cst + acc)
            {
                mn[nxt] = cst + acc; // 최소 비용이 갱신 가능하다면 갱신 후 탐색 노드 큐에 저장
                pq.push(make_pair(-mn[nxt], nxt));
            }
        }
    }
    cout << mn[e]; // 목적지까지의 최소 비용 출력
    return 0;
}