#include <iostream>

using namespace std;

// 배추밭 가로(M), 세로(N), 배추 개수(K)
int M, N, K;

// 배추밭 정보 (1이면 배추가 심어져 있음)
int arr[50][50];

// 방문 여부 체크 배열
bool visited[50][50];

// DFS로 하나의 배추 군집(연결된 배추 묶음) 탐색
void dfs(int r, int c) {
    // 상, 하, 좌, 우 이동 방향 (행, 열 기준)
    int nx[4] = { -1, 0, 1, 0 };
    int ny[4] = { 0, 1, 0, -1 };

    // 네 방향으로 이동하면서 인접한 배추 탐색
    for (int i = 0; i < 4; i++) {
        int nr = r + nx[i];   // 다음 행
        int nc = c + ny[i];   // 다음 열

        // 배추밭 범위를 벗어나면 무시
        // 세로는 N(행), 가로는 M(열)
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            continue;
        }

        // 아직 방문하지 않았고 배추가 있다면
        if (!visited[nr][nc] && arr[nr][nc] == 1) {
            visited[nr][nc] = true;  // 방문 처리
            dfs(nr, nc);             // 재귀로 계속 탐색
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;   // 테스트 케이스 수
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        // 배추밭 크기(M: 가로, N: 세로)와 배추 개수 입력
        cin >> M >> N >> K;

        // 배추 위치 입력
        // 입력 좌표 (X, Y)는 (가로, 세로) → arr[Y][X]에 저장
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            arr[Y][X] = 1;
        }

        int cnt = 0;  // 필요한 지렁이 수 = 배추 군집 개수

        // 배추밭 전체 탐색
        // 행: 0 ~ N-1, 열: 0 ~ M-1
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 방문하지 않았고 배추가 있다면 새로운 군집 시작
                if (!visited[i][j] && arr[i][j] == 1) {
                    visited[i][j] = true; // 시작 위치 방문 처리
                    dfs(i, j);            // 해당 군집 전체 탐색
                    cnt++;                // 군집 하나 발견 → 지렁이 1마리 추가
                }
            }
        }

        // 결과 출력
        cout << cnt << "\n";

        // 다음 테스트 케이스를 위해 배열 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }

    return 0;
}
