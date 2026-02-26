#include <iostream>
using namespace std;

// 최대 128×128 색종이 정보를 저장하는 배열
// board[i][j] : (i, j) 위치의 색 (0 = 흰색, 1 = 파란색)
int board[128][128];

// 결과 카운트
int white = 0;   // 흰색 색종이 개수
int blue = 0;    // 파란색 색종이 개수

/*
 * (x, y)를 좌상단으로 하는 l × l 영역을 검사하는 함수
 * - 영역이 모두 같은 색이면 해당 색 카운트 증가
 * - 다른 색이 섞여 있으면 4등분하여 재귀적으로 검사
 */
void check(int x, int y, int l) {
    // 현재 영역의 기준 색 (좌상단)
    int first_color = board[x][y];

    // 현재 l × l 영역이 모두 같은 색인지 검사
    for (int i = x; i < x + l; i++) {
        for (int j = y; j < y + l; j++) {
            // 기준 색과 다른 색이 하나라도 발견되면 분할
            if (board[i][j] != first_color) {
                int k = l / 2;  // 영역을 4등분할 크기

                // 4개의 사분면을 재귀적으로 검사
                check(x, y, k);             // 왼쪽 위
                check(x, y + k, k);         // 오른쪽 위
                check(x + k, y, k);         // 왼쪽 아래
                check(x + k, y + k, k);     // 오른쪽 아래

                return; // 분할했으므로 현재 영역은 카운트하지 않음
            }
        }
    }

    // 여기까지 왔다는 것은 영역이 모두 같은 색이라는 뜻
    if (first_color == 1) {
        blue++;   // 파란색 색종이 1개
    }
    else {
        white++;  // 흰색 색종이 1개
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  // 전체 색종이의 한 변 길이 (2^k)
    cin >> N;

    // 색종이 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 전체 영역부터 분할 정복 시작
    check(0, 0, N);

    // 결과 출력
    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}
