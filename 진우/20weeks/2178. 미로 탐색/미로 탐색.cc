#include <iostream>
#include <queue>

using namespace std;

int N, M;                 // 미로 크기 (N행, M열)

int arr[100][100];       // 미로 정보 (1: 길, 0: 벽)
int visited[100][100];   // 방문 여부 + 최단 거리 저장 (0이면 미방문)

void bfs(int r, int c) {
    // 상, 우, 하, 좌 방향 이동 배열
    int nx[4] = { -1, 0, 1, 0 };
    int ny[4] = { 0, 1, 0, -1 };

    // BFS용 큐 (좌표 저장)
    queue<pair<int, int>> q;

    // 시작 위치 방문 처리 (거리 = 1)
    visited[r][c] = 1;
    q.push(pair<int, int>(r, c));

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 현재 위치 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nr = x + nx[i];
            int nc = y + ny[i];

            // 미로 범위 밖이면 무시
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 벽이거나 이미 방문한 칸이면 무시
            if (arr[nr][nc] == 0 || visited[nr][nc] != 0) continue;

            // 이동 가능하면 거리 갱신
            visited[nr][nc] = visited[x][y] + 1;

            // 큐에 다음 위치 추가
            q.push(pair<int, int>(nr, nc));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;   // 미로 크기 입력

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';   // 문자 '0','1' → 숫자 0,1
        }
    }

    // (0,0)에서 BFS 시작
    bfs(0, 0);

    // 도착 지점까지의 최단 거리 출력
    cout << visited[N - 1][M - 1] << "\n";

    return 0;
}
