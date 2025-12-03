#include <iostream>

using namespace std;

// 소수 판별 함수
// x가 소수이면 true, 소수가 아니면 false 반환
bool isPrime(long long x) {
    if (x < 2) {        // 0과 1은 소수가 아님
        return false;
    }
    // 2부터 √x 까지 나누어 떨어지는 수가 있는지 검사
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {   // 나누어 떨어지는 수가 존재하면 소수 X
            return false;
        }
    }
    return true;    // 끝까지 나누어 떨어지지 않으면 소수
}

// n 이상 중에서 가장 가까운 소수를 반환
long long nextPrime(long long y) {
    // 소수가 나올 때까지 y 증가시키며 검사
    while (!isPrime(y)) {
        y++;
    }
    return y;
}

int main() {
    int T;
    cin >> T;   // 테스트 케이스 개수 입력

    long long n;
    for (int i = 0; i < T; i++) {
        cin >> n;              // 숫자 입력
        cout << nextPrime(n) << "\n";  // n 이상 가장 가까운 소수 출력
    }

    return 0;
}
