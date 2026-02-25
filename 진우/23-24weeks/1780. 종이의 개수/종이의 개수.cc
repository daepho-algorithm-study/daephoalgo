#include <iostream>
using namespace std;

// 최대 3^7 × 3^7 (= 2187 × 2187) 종이 정보를 저장하는 배열
// board[i][j] : (i, j) 위치의 값 (-1, 0, 1)
int board[2187][2187];

// 결과 카운트
int zero = 0;   // 값이 0인 종이 개수
int one = 0;    // 값이 1인 종이 개수
int other = 0;  // 값이 -1인 종이 개수

/*
 * (x, y)를 좌상단으로 하는 l × l 영역을 검사하는 함수
 *
 * - 영역이 모두 같은 값이면 해당 값 카운트 증가
 * - 다른 값이 섞여 있으면 영역을 3 × 3 (총 9개)로 분할하여 재귀 호출
 */
void check(int x, int y, int l) {
    // 현재 영역의 기준 값 (좌상단)
    int first_color = board[x][y];

    // 현재 l × l 영역이 모두 같은 값인지 확인
    for (int i = x; i < x + l; i++) {
        for (int j = y; j < y + l; j++) {
            // 기준 값과 다른 값이 하나라도 발견되면 분할
            if (board[i][j] != first_color) {

                int k = l / 3;  // 영역을 3등분할 크기

                // 3 × 3 형태로 총 9개의 영역을 재귀적으로 검사
                check(x, y, k);
                check(x, y + k, k);
                check(x, y + (2 * k), k);

                check(x + k, y, k);
                check(x + k, y + k, k);
                check(x + k, y + (2 * k), k);

                check(x + (2 * k), y, k);
                check(x + (2 * k), y + k, k);
                check(x + (2 * k), y + (2 * k), k);

                return;  // 분할했으므로 현재 영역은 카운트하지 않음
            }
        }
    }

    // 여기까지 왔다는 것은 영역이 모두 같은 값이라는 뜻
    if (first_color == 1) {
        one++;       // 값이 1인 종이
    }
    else if (first_color == 0) {
        zero++;      // 값이 0인 종이
    }
    else {
        other++;     // 값이 -1인 종이
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  // 종이 한 변의 길이 (3의 제곱수)
    cin >> N;

    // 종이 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 전체 영역부터 분할 정복 시작
    check(0, 0, N);

    // 문제에서 요구한 순서대로 출력
    cout << other << "\n"; // -1 개수
    cout << zero << "\n";  // 0 개수
    cout << one << "\n";   // 1 개수

    return 0;
}