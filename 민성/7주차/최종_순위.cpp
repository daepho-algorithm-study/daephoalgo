#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> last(n); // 작년 등수 저장 배열
        // 상대 등수 체크 배열
        vector<vector<bool>> rank(n + 1, vector<bool>(n + 1, false));
        vector<vector<int>> node(n + 1); // 관계 저장 배열
        vector<int> deg(n + 1, 0);       // 진입 차수 저장 배열
        vector<int> cur;                 // 올해 등수 저장 배열
        queue<int> q;                    // 위상 정렬 구현 큐
        for (int i = 0; i < n; i++)
            cin >> last[i]; // 작년 등수 저장
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                rank[last[i]][last[j]] = true; // 상대 등수 우위 체크
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            rank[a][b] = !rank[a][b]; // 상대 등수 우위 스위칭
            rank[b][a] = !rank[b][a];
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (rank[i][j])
                {
                    node[i].push_back(j); // 등수 관계 노드에 저장
                    deg[j]++;             // 진입차수 카운팅
                }
        for (int i = 1; i <= n; i++)
            if (!deg[i])
                q.push(i); // 진입차수가 0인 노드 큐에 삽입
        for (int k = 0; k < n; k++)
        {
            if (q.empty())
            {
                cout << "IMPOSSIBLE"; // 사이클 존재할 경우 처리
                break;
            }
            if (q.size() > 1)
            {
                cout << "?"; // 중복 정답 존재 경우 처리
                break;
            }
            int team = q.front(); // 팀 번호 할당
            q.pop();
            cur.push_back(team); // 올해 배열에 추가
            for (int i = 0; i < node[team].size(); i++)
            {
                int nxt = node[team][i];
                deg[nxt]--; // 해당 팀과의 관계 제거
                if (!deg[nxt])
                    q.push(nxt); // 진입차수가 0이 됬으면 큐에 삽입
            }
        }
        if (cur.size() == n)
            for (int i = 0; i < n; i++)
                cout << cur[i] << " ";
        cout << "\n";
    }
    return 0;
}