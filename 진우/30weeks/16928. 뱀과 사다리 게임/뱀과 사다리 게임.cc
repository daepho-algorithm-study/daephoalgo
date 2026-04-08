#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 사다리/뱀 정보 저장
// board[x] = y → x에 도착하면 y로 이동
int board[101];

// 각 칸까지 도달하는 최소 주사위 횟수 저장
// -1이면 아직 방문하지 않은 상태
vector<int> visited(101, -1);

// BFS로 최소 이동 횟수 탐색
void bfs(int a) {
    queue<int> q;
    q.push(a);

    // 시작 위치는 이동 횟수 0
    visited[a] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 100번 칸 도달 시 종료 (최소 횟수 보장됨)
        if (cur == 100) {
            return;
        }
        
        // 주사위 1~6까지 모든 경우 탐색
        for (int i = 1; i <= 6; i++) {
            int move = cur + i;

            // 100번 초과하면 이동 불가
            if (move > 100) {
                continue;
            }

            // 사다리 또는 뱀이 있으면 해당 위치로 이동
            if (board[move] != 0) {
                move = board[move];
            }

            // 아직 방문하지 않은 칸이면
            if (visited[move] == -1) {
                // 현재까지 횟수 + 1 (주사위 한 번 사용)
                visited[move] = visited[cur] + 1;

                // 다음 탐색을 위해 큐에 추가
                q.push(move);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 사다리(N) + 뱀(M) 정보 입력
    for (int i = 0; i < N + M; i++) {
        int x, y;
        cin >> x >> y;

        // x에 도착하면 y로 이동
        board[x] = y;
    }

    // 1번 칸에서 시작
    bfs(1);

    // 100번 칸까지 가는 최소 주사위 횟수 출력
    cout << visited[100] << "\n";

    return 0;
}