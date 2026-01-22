#include <iostream>
#include <vector>

using namespace std;

// 인접 리스트: 각 정점에 연결된 정점들을 저장
vector<int> arr[101];

// 방문 여부 체크 배열
bool visited[101];

// 1번 컴퓨터로부터 감염되는 컴퓨터 수
int cnt = 0;

// 깊이 우선 탐색(DFS)
void dfs(int n) {
    // 현재 노드를 방문 처리
    visited[n] = true;

    // 현재 노드와 연결된 모든 노드 탐색
    for (int i = 0; i < arr[n].size(); i++) {
        int nxt = arr[n][i];

        // 아직 방문하지 않은 노드라면
        if (!visited[nxt]) {
            cnt++;      // 새로 감염되는 컴퓨터 수 증가
            dfs(nxt);   // 다음 노드로 DFS 진행
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;   // 컴퓨터 수
    cin >> N;

    int M;   // 연결된 쌍의 개수
    cin >> M;

    // 그래프 입력 (양방향 연결)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 1번 컴퓨터부터 DFS 시작
    dfs(1);

    // 감염된 컴퓨터 수 출력 (1번 제외)
    cout << cnt << "\n";
}
