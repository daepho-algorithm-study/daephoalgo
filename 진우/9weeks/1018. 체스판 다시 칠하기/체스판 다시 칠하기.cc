#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // 체스판의 크기 입력 (N행 M열)

    vector<string> board(N); // 문자열 형태로 체스판 저장
    for (int i = 0; i < N; i++) {
        cin >> board[i]; // 각 행 입력 (예: "WBWBWBWB")
    }

    int min_count = 64; // 최소 다시 칠해야 하는 칸 수 (최대 8x8 = 64)

    // 가능한 모든 8x8 구간을 순회
    for (int i = 0; i <= N - 8; i++) {       // 시작 행
        for (int j = 0; j <= M - 8; j++) {   // 시작 열

            int start_W = 0; // 왼쪽 위가 'W'로 시작하는 경우의 다시 칠해야 할 칸 수
            int start_B = 0; // 왼쪽 위가 'B'로 시작하는 경우의 다시 칠해야 할 칸 수

            // 선택된 8x8 부분 체스판 검사
            for (int k = i; k < i + 8; k++) {       // 행 범위
                for (int l = j; l < j + 8; l++) {   // 열 범위
                    // (k + l)의 합이 짝수 → 기준색 위치 / 홀수 → 반대색 위치
                    if ((k + l) % 2 == 0) {
                        // 짝수 칸 (왼쪽 위 색과 같은 위치)
                        if (board[k][l] != 'W') start_W++; // 'W'로 시작 시 잘못된 칸
                        if (board[k][l] != 'B') start_B++; // 'B'로 시작 시 잘못된 칸
                    } else {
                        // 홀수 칸 (왼쪽 위 색과 반대 위치)
                        if (board[k][l] != 'B') start_W++; // 'W'로 시작 시 잘못된 칸
                        if (board[k][l] != 'W') start_B++; // 'B'로 시작 시 잘못된 칸
                    }
                }
            }

            // 해당 8x8 체스판에서 두 패턴 중 더 적게 칠하는 경우 선택
            min_count = min({min_count, start_W, start_B});
        }
    }

    cout << min_count << "\n"; // 결과 출력 (최소 다시 칠해야 하는 칸 수)
    return 0;
}
