#include <iostream>
#include <deque>

using namespace std;

int I;                     // 체스판 한 변의 길이
int position[4];           // [0]=시작 x, [1]=시작 y
                           // [2]=목표 x, [3]=목표 y
int visited[300][300];     // visited[r][c]
                           // -1 : 아직 방문하지 않음
                           //  0 이상 : (r,c)까지의 최소 이동 횟수

// BFS 함수
// (x, y)에서 시작해서 목표 위치까지의 최소 나이트 이동 횟수를 계산
void bfs(int x, int y) {
    // 나이트의 이동 방향 (총 8가지)
    int nx[8] = { -1, -2, -2, -1,  1,  2,  2,  1 };
    int ny[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };

    // 시작 위치 방문 처리
    // 시작점은 이동 횟수 0
    visited[x][y] = 0;

    // BFS용 큐 (좌표 저장)
    deque<pair<int, int>> q;
    q.push_back({ x, y });

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 현재 위치 꺼내기
        pair<int, int> cur = q.front();
        q.pop_front();

        int row = cur.first;
        int col = cur.second;

        // 목표 위치에 도착하면 종료
        // BFS이므로 이 순간의 값이 최단 거리
        if (row == position[2] && col == position[3]) return;

        // 나이트의 8가지 이동 방향 탐색
        for (int i = 0; i < 8; i++) {
            int nr = row + nx[i];
            int nc = col + ny[i];

            // 체스판 범위를 벗어나면 무시
            if (nr < 0 || nr >= I || nc < 0 || nc >= I) continue;

            // 아직 방문하지 않은 칸이면
            if (visited[nr][nc] == -1) {
                // 현재 칸에서 1번 이동한 거리 저장
                visited[nr][nc] = visited[row][col] + 1;

                // 다음 탐색을 위해 큐에 추가
                q.push_back({ nr, nc });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                 // 테스트 케이스 수
    cin >> T;

    // 각 테스트 케이스 처리
    for (int tc = 0; tc < T; tc++) {
        cin >> I;          // 체스판 크기 입력

        // 시작 좌표 입력
        cin >> position[0] >> position[1];
        // 목표 좌표 입력
        cin >> position[2] >> position[3];

        // visited 배열을 -1로 초기화
        // (모든 칸을 아직 방문하지 않은 상태로 만듦)
        for (int i = 0; i < I; i++) {
            for (int j = 0; j < I; j++) {
                visited[i][j] = -1;
            }
        }

        // BFS 실행 (시작 좌표에서 탐색 시작)
        bfs(position[0], position[1]);

        // 목표 좌표까지의 최소 이동 횟수 출력
        cout << visited[position[2]][position[3]] << "\n";
    }

    return 0;
}
