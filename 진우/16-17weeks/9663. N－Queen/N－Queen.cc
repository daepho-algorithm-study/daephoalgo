#include <iostream>
#include <vector>

using namespace std;

int N;                 // 체스판 크기 (N x N)
int cnt = 0;           // 가능한 N-Queen 배치 개수
vector<int> board;     // board[row] = 해당 row에 놓인 퀸의 column

// 현재 row에 놓은 퀸이
// 이전 행(row 이전)에 놓인 퀸들과 충돌하는지 검사
bool check(int row) {

    // row보다 위에 있는 행들만 검사
    // (아래 행에는 아직 퀸을 배치하지 않았음)
    for (int i = 0; i < row; i++) {

        // 같은 열에 퀸이 있는 경우
        if (board[i] == board[row])
            return false;

        // ↘ 대각선 충돌
        // (row + col 값이 같으면 같은 대각선)
        if (i + board[i] == row + board[row])
            return false;

        // ↙ 대각선 충돌
        // (row - col 값이 같으면 같은 대각선)
        if (i - board[i] == row - board[row])
            return false;
    }

    // 어떤 조건에도 걸리지 않으면 안전한 위치
    return true;
}

// DFS + 백트래킹 함수
// row번째 행에 퀸을 배치하는 과정
void queen(int row) {

    // 기저 조건
    // 모든 행(0 ~ N-1)에 퀸을 배치 완료한 경우
    if (row == N) {
        cnt++;     // 하나의 완성된 경우의 수
        return;
    }

    // 현재 행(row)에 대해 모든 열(col)을 하나씩 시도
    for (int col = 0; col < N; col++) {

        // (row, col)에 퀸을 놓아본다
        board[row] = col;

        // 이전 행들과 충돌하지 않는다면
        if (check(row)) {
            // 다음 행으로 이동 (DFS)
            queen(row + 1);
        }
        // 충돌하는 경우는 자동으로 다음 col 시도
        // (백트래킹)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;               // 체스판 크기 입력
    board = vector<int>(N, -1);  // 각 행의 퀸 위치 초기화

    // 0번째 행부터 퀸 배치 시작
    queen(0);

    // 가능한 배치 개수 출력
    cout << cnt << '\n';
    return 0;
}
