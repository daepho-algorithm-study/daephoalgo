#include <iostream>
using namespace std;

// w(a, b, c)의 결과를 저장해 두는 메모이제이션 배열
// a, b, c는 최대 20까지만 의미 있으므로 크기를 21로 잡음
int arr[21][21][21];

// 재귀 함수 w(a, b, c)
int w(int a, int b, int c) {

    // 종료 조건 1:
    // a, b, c 중 하나라도 0 이하이면 항상 1 반환
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    // 종료 조건 2:
    // a, b, c 중 하나라도 20 초과면 w(20, 20, 20)과 동일
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    // 이미 계산한 값이 있으면 재귀 호출 없이 바로 반환
    else if (arr[a][b][c] != 0)
        return arr[a][b][c];

    // 조건: a < b < c 인 경우
    // 문제에서 주어진 공식 그대로 사용
    else if (a < b && b < c)
        arr[a][b][c] = w(a, b, c - 1)
                     + w(a, b - 1, c - 1)
                     - w(a, b - 1, c);

    // 그 외의 모든 경우
    // 문제에서 주어진 공식 그대로 사용
    else
        arr[a][b][c] = w(a - 1, b, c)
                     + w(a - 1, b - 1, c)
                     + w(a - 1, b, c - 1)
                     - w(a - 1, b - 1, c - 1);

    // 계산한 값을 배열에 저장해 두고 반환
    return arr[a][b][c];
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;

    // -1 -1 -1 이 나올 때까지 계속 입력 받음
    while (true) {
        cin >> a >> b >> c;

        // 종료 조건
        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        // 결과 출력 형식은 문제 요구사항 그대로
        cout << "w(" << a << ", " << b << ", " << c << ") = " 
             << w(a, b, c) << endl;
    }

    return 0;
}
