#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int deg[32001]; // 진입차수 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    // 먼저 풀어야 할 문제 저장 큐
    priority_queue<int, vector<int>, greater<int>> prob;
    cin >> n >> m;
    vector<vector<int>> node(n + 1); // 문제 관계 저장 배열
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        node[a].push_back(b); // 관계 저장
        deg[b]++;             // 진입차수 표시
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            prob.push(i); // 진입차수가 0인 문제 큐에 삽입
    while (!prob.empty())
    {
        int p = prob.top(); // 문제 번호 할당
        prob.pop();
        cout << p << " "; // 문제 순서대로 출력
        for (int i = 0; i < node[p].size(); i++)
        {
            int nxt = node[p][i]; // 다음 순서인 문제 할당
            deg[nxt]--;           // 진입차수 제거
            if (deg[nxt] == 0)
                prob.push(nxt); // 진입차수 제거로 인해 진입차수가 0인 된 문제 삽입
        }
    }
    return 0;
}