#include <iostream>   // 표준 입출력
#include <vector>     // vector 사용
#include <cstdlib>    // exit(0) 사용

using namespace std;

// 스도쿠 판 (9x9)
int board[9][9];

// 빈 칸(0)의 좌표를 저장하는 벡터
// pair.first  = 행(row)
// pair.second = 열(col)
vector<pair<int, int>> blank;

/*
 * (row, col)에 num을 놓을 수 있는지 검사하는 함수
 * 1) 같은 행에 num이 있는지
 * 2) 같은 열에 num이 있는지
 * 3) 같은 3x3 박스에 num이 있는지
 */
bool check(int row, int col, int num) {
    // 같은 행(row) 검사
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num) {
            return false;
        }
    }

    // 같은 열(col) 검사
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // 3x3 박스의 시작 좌표 계산
    int nx = (row / 3) * 3;
    int ny = (col / 3) * 3;

    // 3x3 박스 내부 검사
    for (int i = nx; i < nx + 3; i++) {
        for (int j = ny; j < ny + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    // 위 조건을 모두 통과하면 배치 가능
    return true;
}

/*
 * 백트래킹으로 스도쿠를 해결하는 함수
 * n : 현재 채울 빈칸의 인덱스
 */
void sudoku(int n) {
    // 모든 빈칸을 다 채운 경우 → 정답 완성
    if (n == (int)blank.size()) {
        // 완성된 스도쿠 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        // 문제 조건상 해답은 하나이므로 즉시 종료
        exit(0);
    }

    // 현재 빈칸의 좌표
    int r = blank[n].first;
    int c = blank[n].second;

    // 1~9를 하나씩 시도
    for (int num = 1; num <= 9; num++) {
        // (r, c)에 num을 놓을 수 있다면
        if (check(r, c, num)) {
            board[r][c] = num;     // 숫자 배치
            sudoku(n + 1);         // 다음 빈칸으로 진행
            board[r][c] = 0;       // 백트래킹 (원상 복구)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 스도쿠 입력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            // 빈칸이면 좌표 저장
            if (board[i][j] == 0) {
                blank.push_back({ i, j });
            }
        }
    }

    // 스도쿠 해결 시작
    sudoku(0);

    return 0;
}
