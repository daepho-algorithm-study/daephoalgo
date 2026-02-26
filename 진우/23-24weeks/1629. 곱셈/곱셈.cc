#include <iostream>
using namespace std;

/*
 * check(a, b, c)
 * - a^b % c를 재귀적으로 계산하는 함수 (분할정복)
 * - 탑다운 방식, 시간복잡도 O(log b)
 */
long long check(long long a, long long b, long long c) {
    // 종료 조건: 지수가 0이면 a^0 = 1
    if (b == 0) {
        return 1;
    }

    // 재귀: 지수를 절반으로 줄여 계산
    // half = a^(b/2) % c
    long long half = check(a, b / 2, c);

    // 절반 결과를 제곱하고 나머지 연산
    long long result = (half * half) % c;

    // b가 홀수이면 남은 한 번 곱해주기
    if (b % 2 == 1) {
        result = (result * a) % c;
    }

    // 최종 결과 반환
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C; // A^B % C 계산

    // 재귀 호출로 계산 후 출력
    cout << check(A, B, C) << "\n";

    return 0;
}