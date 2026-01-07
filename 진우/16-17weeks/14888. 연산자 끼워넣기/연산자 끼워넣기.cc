#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;                 // 숫자의 개수
vector<int> num;       // 입력된 숫자들을 저장 (크기 N)
int oper[4];           // 연산자 개수: +, -, *, / 순서
int mx = -1000000001;        // 최댓값 저장
int mn = 1000000001;         // 최솟값 저장

/*
 x : 현재까지 계산된 결과값
 n : 다음에 사용할 숫자의 인덱스
     (num[n]을 사용 예정)
*/
void fun(int x, int n) {

    // 모든 숫자를 다 사용한 경우
    // (num[0]부터 num[N-1]까지 전부 계산 완료)
    if (n == N) {
        if (x > mx) mx = x;   // 최댓값 갱신
        if (x < mn) mn = x;   // 최솟값 갱신
        return;
    }

    // 4가지 연산자를 하나씩 시도
    for (int i = 0; i < 4; i++) {

        // 해당 연산자를 아직 사용할 수 있다면
        if (oper[i] > 0) {
            oper[i]--;    // 연산자 하나 사용

            // 덧셈
            if (i == 0) {
                fun(x + num[n], n + 1);
            }
            // 뺄셈
            else if (i == 1) {
                fun(x - num[n], n + 1);
            }
            // 곱셈
            else if (i == 2) {
                fun(x * num[n], n + 1);
            }
            // 나눗셈 (C++ 정수 나눗셈: 0 방향으로 버림)
            else {
                fun(x / num[n], n + 1);
            }

            oper[i]++;    // 백트래킹: 사용한 연산자 복구
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;           // 숫자 개수 입력

    // 숫자 입력 (미리 resize로 크기 확보)
    num.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // 연산자 개수 입력 (+, -, *, /)
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    // 첫 번째 숫자를 초기값으로 시작
    // n = 1 → 다음에 사용할 숫자는 num[1]
    fun(num[0], 1);

    // 결과 출력
    cout << mx << "\n";
    cout << mn << "\n";

    return 0;
}
