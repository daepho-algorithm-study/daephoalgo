#include <iostream>
#include <string>
#include <queue>

using namespace std;

// N x M 미로 크기
int N, M;

// 미로 정보
// 0: 빈 칸, 1: 벽
int board[1001][1001];

// visited[x][y][wall]
// x, y: 좌표
// wall: 벽을 부쉈는지 여부 (0=안부숨, 1=부숨)
// 값: 시작점부터 해당 좌표까지의 이동 거리
int visited[1001][1001][2];

// 상, 우, 하, 좌
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// BFS로 최단 경로 탐색
int bfs() {
    // 큐: ((x, y), wall) 형태
    queue<pair<pair<int, int>, int>> q;

    // 시작점 (1,1), 벽 안 부숨
    q.push({ {1, 1}, 0 });
    visited[1][1][0] = 1; // 거리 1부터 시작 (자기 자신 포함)

    while (!q.empty()) {
        // 현재 위치와 벽 사용 여부 가져오기
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        // 목표 지점 도착 시, 거리 반환
        if (x == N && y == M) {
            return visited[x][y][wall];
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 벗어나면 넘어감
            if (nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }

            // 1. 빈 칸 이동 가능
            if (board[nx][ny] == 0 && visited[nx][ny][wall] == 0) {
                visited[nx][ny][wall] = visited[x][y][wall] + 1;
                q.push({ {nx, ny}, wall });
            }

            // 2. 벽을 부술 수 있는 경우 (한 번만 가능)
            if (board[nx][ny] == 1 && wall == 0 && visited[nx][ny][1] == 0) {
                visited[nx][ny][1] = visited[x][y][wall] + 1;
                q.push({ {nx, ny}, 1 });
            }
        }
    }

    // 도달 불가 시 -1 반환
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 미로 크기 입력
    cin >> N >> M;

    // 미로 정보 입력
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            board[i][j] = s[j - 1] - '0'; // 문자열 -> 정수 변환
        }
    }

    // BFS 실행 후 최단 거리 출력
    cout << bfs() << "\n";

    return 0;
}