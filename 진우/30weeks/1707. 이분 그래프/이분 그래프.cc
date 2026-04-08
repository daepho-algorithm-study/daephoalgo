#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS를 이용한 이분 그래프 판별 함수
bool bfs(int V, vector<vector<int>>& arr) {
    // color 배열: 각 노드의 색상 저장
    // 0: 미방문, 1: 빨강, -1: 파랑
    vector<int> color(V + 1, 0);

    // 모든 노드를 순회 (그래프가 연결되어 있지 않을 수 있기 때문에)
    for (int i = 1; i <= V; i++) {
        if (color[i] != 0) {
            continue; // 이미 방문한 노드는 건너뜀
        }
        
        queue<int> q;     // BFS용 큐
        q.push(i);        // 시작 노드 삽입
        color[i] = 1;     // 시작 노드를 빨강(1)으로 색칠

        // BFS 탐색
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // 현재 노드와 연결된 모든 인접 노드 확인
            for (int j = 0; j < arr[cur].size(); j++) {
                int nxt = arr[cur][j];

                if (color[nxt] == 0) {
                    // 방문하지 않은 노드라면, 현재 노드와 반대 색으로 칠함
                    color[nxt] = -color[cur];
                    q.push(nxt); // 큐에 삽입하여 탐색 계속
                }
                else if (color[nxt] == color[cur]) {
                    // 인접 노드가 현재 노드와 같은 색이면
                    // 이분 그래프 조건 위배 → false 반환
                    return false;
                }
            }
        }
    }

    // 모든 노드 탐색 후 이상 없으면 이분 그래프
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(nullptr);

    int K; // 테스트케이스 수
    cin >> K;

    for (int tc = 0; tc < K; tc++) {
        int V, E; // 정점, 간선 수
        cin >> V >> E;

        // 그래프 인접리스트 초기화
        vector<vector<int>> arr(V + 1);

        // 간선 정보 입력
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v); // 양방향 그래프
            arr[v].push_back(u);
        }

        // BFS로 이분 그래프 판별
        if (bfs(V, arr)) {
            cout << "YES\n"; // 이분 그래프일 경우
        }
        else {
            cout << "NO\n";  // 이분 그래프가 아닐 경우
        }
    }

    return 0;
}