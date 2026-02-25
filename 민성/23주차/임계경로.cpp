#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 진입차수와 누적 시간 저장 배열
int deg[10001], t[10001];
// 방문 체크 배열
bool visited[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v, w, s, e;
    cin >> n >> m;
    // 도로 정보 저장 배열
    vector<vector<pair<int, int>>> load(n + 1);
    // 역추적 배열
    vector<vector<pair<int, int>>> rv(n + 1);
    // 도로 정보와 진입차수 저장
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        load[u].push_back({v, w});
        rv[v].push_back({u, w});
        deg[v]++;
    }
    // 출발점(한걸음)과 종착점(로마) 정보 저장
    cin >> s >> e;
    // 위상 정렬 구현 큐 할당
    queue<int> q;
    // 시작점 삽입
    q.push(s);
    // 진입차수가 모두 0이 될 때까지 반복
    while (!q.empty())
    {
        // 진입 차수 0인 노드 추출
        s = q.front();
        q.pop();
        for (int i = 0; i < load[s].size(); i++)
        {
            // 도착점과 시간 할당
            v = load[s][i].first, w = load[s][i].second;
            // 누적 시간과 도로 개수 갱신
            if (t[v] < t[s] + w)
                t[v] = t[s] + w;
            // 진입차수 차감
            deg[v]--;
            // 진입 차수가 0이 되면 큐에 삽입
            if (!deg[v])
                q.push(v);
        }
    }
    cout << t[e] << "\n";
    // 황금칠할 도로 개수 저장 변수
    int cnt = 0;
    // 황금칠할 도로 역추적을 위해 도착점 큐에 삽입
    q.push(e);
    while (!q.empty())
    {
        e = q.front();
        q.pop();
        for (int i = 0; i < rv[e].size(); i++)
        {
            v = rv[e][i].first, w = rv[e][i].second;
            // 누적 시간의 합이 도착점과 동일하다면 황금칠할 도로
            if (t[e] == t[v] + w)
            {
                cnt++;
                // 방문하지 않은 노드면 큐에 삽입
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}