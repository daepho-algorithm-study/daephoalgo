#include <iostream>
#include <queue>

using namespace std;

// 격자의 세로(N), 가로(M)
int N, M;

// 토마토 상태를 저장하는 배열
// -1: 토마토 없음, 0: 안 익음, 1 이상: 익은 날짜
int box[1001][1001];

// 최댓값(가장 늦게 익은 날짜)을 저장
int mx = -99999999;

// BFS를 위한 큐 (좌표 저장)
queue<pair<int, int>> q;

// 상, 좌, 하, 우 방향 벡터
int nx[4] = { -1, 0, 1, 0 };
int ny[4] = { 0, -1, 0, 1 };

// BFS 수행 함수
void bfs() {
    // 큐가 빌 때까지 탐색
	while (!q.empty()) {

        // 현재 위치 꺼내기
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

        // 4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nr = x + nx[i];
			int nc = y + ny[i];

            // 범위 밖이면 무시
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 아직 익지 않은 토마토(0)만 전파
            // -1은 토마토가 없는 칸
			if (box[nr][nc] == 0) {
                // 현재 날짜 + 1로 익음 처리
				box[nr][nc] = box[x][y] + 1;

                // 다음 탐색을 위해 큐에 삽입
				q.push({ nr, nc });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // 입력: M(가로), N(세로)
	cin >> M >> N;

    // 토마토 정보 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];

            // 이미 익은 토마토(1)를
            // BFS 시작점으로 큐에 넣음 (다중 시작점)
			if (box[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

    // BFS 실행
	bfs();

    // 결과 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

            // 아직 안 익은 토마토가 남아있으면 실패
			if (box[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}

            // 가장 늦게 익은 날짜 갱신
			if (box[i][j] > mx) {
				mx = box[i][j];
			}
		}
	}

    // 시작 날짜가 1이므로 -1 해줘야 실제 일수
	cout << mx - 1 << "\n";

	return 0;
}
