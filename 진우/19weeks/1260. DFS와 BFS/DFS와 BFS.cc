#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// 인접 리스트: 각 정점에 연결된 정점 목록
vector<int> arr[1001];

// DFS 방문 여부 체크 배열
bool dfs_visited[1001];

// BFS 방문 여부 체크 배열
bool bfs_visited[1001];

// 깊이 우선 탐색(DFS)
void dfs(int v) {
    // 현재 정점을 방문 처리
    dfs_visited[v] = true;

    // 방문한 정점 출력
    cout << v << " ";

    // 현재 정점과 연결된 모든 정점 탐색
    for (int i = 0; i < arr[v].size(); i++) {
        int nxt = arr[v][i];

        // 아직 방문하지 않았다면 재귀 호출
        if (!dfs_visited[nxt]) {
            dfs(nxt);
        }
    }
}

// 너비 우선 탐색(BFS)
void bfs(int v) {
    deque<int> q;

    // 시작 정점을 큐에 삽입
    q.push_back(v);
    bfs_visited[v] = true;

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int node = q.front();
        q.pop_front();

        // 현재 정점 출력
        cout << node << " ";

        // 현재 정점과 연결된 모든 정점 탐색
        for (int i = 0; i < arr[node].size(); i++) {
            int nxt = arr[node][i];

            // 아직 방문하지 않았다면 큐에 삽입
            if (!bfs_visited[nxt]) {
                bfs_visited[nxt] = true;
                q.push_back(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    // 간선 정보 입력 (양방향 그래프)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 문제 조건에 따라 작은 번호부터 방문하기 위해 정렬
    for (int i = 1; i <= N; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    // DFS 수행 및 출력
    dfs(V);
    cout << "\n";

    // BFS 수행 및 출력
    bfs(V);
    cout << "\n";

    return 0;
}
