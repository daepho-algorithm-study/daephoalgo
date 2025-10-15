#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int deg[1001]; // 진입 차수 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num;
    cin >> n >> m;
    vector<vector<int>> node(n + 1); // 위상 정렬을 위한 노드 관계 저장 배열
    vector<int> ans;                 // 정답 출력 배열
    queue<int> q;                    // 진입 차수가 0인 노드 저장 큐
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        vector<int> seq(num); // PD가 정한 순서 저장 배열
        for (int j = 0; j < num; j++)
            cin >> seq[j]; // 순서 저장
        for (int j = 0; j < num - 1; j++)
        {
            node[seq[j]].push_back(seq[j + 1]); // 순서로 인한 관계 저장
            deg[seq[j + 1]]++;                  // 진입차수 표시
        }
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i); // 진입차수가 0인 노드 큐에 삽입
    while (!q.empty())
    {
        int p = q.front(); // 가수 번호 할당
        q.pop();
        ans.push_back(p); // 정답 배열에 해당 가수 번호 저장
        for (int i = 0; i < node[p].size(); i++)
        {
            deg[node[p][i]]--; // 해당 가수 관계 제거
            if (deg[node[p][i]] == 0)
                q.push(node[p][i]); // 진입차수가 0이 된 노드 큐에 삽입
        }
    }
    if (ans.size() < n)
        cout << 0; // 순서를 정할 수 없으면 0 출력
    else
        for (int i = 0; i < n; i++)
            cout << ans[i] << "\n"; // 정답 배열 출력
    return 0;
}