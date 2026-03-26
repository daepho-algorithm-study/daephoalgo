#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 원본 체스판 배열 (B / W 입력)
char board[2001][2001];

// 누적합 배열
// b[i][j] : (1,1) ~ (i,j)까지 "B로 시작하는 체스판" 기준에서 다시 칠해야 하는 칸 수
// w[i][j] : (1,1) ~ (i,j)까지 "W로 시작하는 체스판" 기준에서 다시 칠해야 하는 칸 수
int b[2001][2001];
int w[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    // 입력 + 누적합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];

            // 기본 누적합 공식 (위 + 왼쪽 - 겹치는 부분)
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];

            // 체스판 규칙 적용
            // (i + j)가 짝수인 칸을 기준으로 시작 색이 결정됨
            if ((i + j) % 2 == 0) {
                // B로 시작하는 체스판이라면 이 자리는 'B'가 와야 정상
                // 아니라면 다시 칠해야 하므로 +1
                if (board[i][j] != 'B') {
                    b[i][j]++;
                }

                // W로 시작하는 체스판이라면 이 자리는 'W'가 와야 정상
                if (board[i][j] != 'W') {
                    w[i][j]++;
                }
            }
            else {
                // 홀수 칸은 색이 반대
                if (board[i][j] != 'W') {
                    b[i][j]++;
                }

                if (board[i][j] != 'B') {
                    w[i][j]++;
                }
            }
        }
    }

    // 결과 (최소 다시 칠하는 횟수)
    int result = 9999999;

    // K x K 부분 체스판 탐색
    for (int i = 1; i <= N - K + 1; i++) {
        for (int j = 1; j <= M - K + 1; j++) {

            // 현재 부분 배열의 좌상단 (x1, y1), 우하단 (x2, y2)
            int x1 = i, y1 = j;
            int x2 = i + K - 1, y2 = j + K - 1;

            // 2차원 누적합으로 KxK 영역의 값 빠르게 계산
            // 공식: 전체 - 위 - 왼쪽 + 겹치는 부분
            int B = b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
            int W = w[x2][y2] - w[x1 - 1][y2] - w[x2][y1 - 1] + w[x1 - 1][y1 - 1];

            // 둘 중 더 적게 칠하는 경우 선택
            if (B < W) {
                if (B < result) {
                    result = B;
                }
            }
            else {
                if (W < result) {
                    result = W;
                }
            }
        }
    }

    // 최소값 출력
    cout << result << "\n";

    return 0;
}