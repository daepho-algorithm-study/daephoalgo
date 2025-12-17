#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;      // N과 K 입력

    long long n = 1;
    // N! 계산
    for (int i = N; i >= 1; i--) {
        n *= i;
    }

    long long k = 1;
    // K! 계산
    for (int i = K; i >= 1; i--) {
        k *= i;
    }

    long long r = 1;
    // (N-K)! 계산
    for (int i = (N - K); i >= 1; i--) {
        r *= i;
    }

    // 이항계수 nCk = N! / (K! * (N-K)!)
    int result = n / (k * r);

    cout << result << "\n";  // 결과 출력

    return 0;
}
