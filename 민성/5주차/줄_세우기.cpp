#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> line(32001); // 키 비교 결과 저장 배열
int deg[32001];                  // 진입차수 카운팅 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    queue<int> q; // 위상 정렬을 위한 큐 할당
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        line[a].push_back(b); // 키 비교 결과 저장
        deg[b]++;             // 진입차수 카운팅
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i); // 진입차수가 0인 노드 큐에 삽입
    while (!q.empty())
    {
        int p = q.front(); // 줄 세울 학생 번호 할당
        q.pop();
        cout << p << " "; // 순서대로 학생 출력
        for (int i = 0; i < line[p].size(); i++)
        {
            deg[line[p][i]]--; // 해당 노드와의 관계 제거
            if (deg[line[p][i]] == 0)
                q.push(line[p][i]); // 관계 제거로 진입차수가 0이 된 노드 큐에 삽입
        }
    }
    return 0;
}