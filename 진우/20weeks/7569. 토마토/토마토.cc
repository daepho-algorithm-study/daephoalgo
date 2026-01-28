#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// M: 가로(열), N: 세로(행), H: 높이(층 수)
int M, N, H;

// 3차원 토마토 상자
// box[h][x][y]
// -1: 토마토 없음
//  0: 안 익은 토마토
//  1 이상: 익은 날짜
int box[100][100][100];

// BFS를 위한 큐
// vector<int>에 [높이(h), 행(x), 열(y)] 순서로 저장
queue<vector<int>> q;

// 가장 늦게 익은 날짜 저장
int mx = -999999;

// 같은 층에서의 4방향 이동 (우, 하, 좌, 상)
int nx[4] = { 0, 1, 0, -1 };
int ny[4] = { 1, 0, -1, 0 };

// 위층(-1), 아래층(+1) 이동
int nz[2] = { -1, 1 };

// BFS 수행 함수
void bfs() {
	while (!q.empty()) {

        // 큐에서 현재 좌표 꺼내기
        // h: 높이, x: 행, y: 열
		int x = q.front()[1];
		int y = q.front()[2];
		int h = q.front()[0];
		q.pop();

        // 같은 층에서 상하좌우 4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nr = x + nx[i];
			int nc = y + ny[i];

            // 행, 열 범위 체크
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 아직 익지 않은 토마토만 전파
			if (box[h][nr][nc] == 0) {
                // 현재 날짜 + 1로 익음 처리
				box[h][nr][nc] = box[h][x][y] + 1;

                // 다음 탐색을 위해 큐에 추가
				q.push(vector<int>{h, nr, nc});
			}
		}

        // 위층 / 아래층(높이) 방향 탐색
		for (int k = 0; k < 2; k++) {
			int nh = h + nz[k];

            // 높이 범위 체크
			if (nh < 0 || nh >= H) continue;

            // 같은 위치에서 위/아래 층 토마토 확인
			if (box[nh][x][y] == 0) {
				box[nh][x][y] = box[h][x][y] + 1;
				q.push(vector<int>{nh, x, y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // 입력: M(가로), N(세로), H(높이)
	cin >> M >> N >> H;

    // 토마토 정보 입력
    // 높이(h) → 세로(x) → 가로(y) 순서
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];

                // 이미 익은 토마토는 BFS 시작점
				if (box[i][j][k] == 1)
					q.push(vector<int>{i, j, k});
			}
		}
	}

    // BFS 실행 (토마토 전파)
	bfs();

    // 결과 확인
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {

                // 익지 않은 토마토가 남아 있으면 실패
				if (box[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}

                // 가장 늦게 익은 날짜 갱신
				if (box[i][j][k] > mx)
					mx = box[i][j][k];
			}
		}
	}

    // 시작 날짜가 1이므로 -1
	cout << mx - 1 << "\n";

	return 0;
}
