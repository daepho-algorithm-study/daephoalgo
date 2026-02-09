#include <iostream>
using namespace std;

const int MOD = 1000000000;    // 문제에서 요구하는 나머지 값
long long dp[101][10];         // dp[i][j] : 길이가 i이고 마지막 자리가 j인 계단 수의 개수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;                  // 계단 수의 길이 입력

    /* ===============================
       초기값 설정 (길이 1)
       =============================== */
    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }
    dp[1][0] = 0;

    /* ===============================
       DP 계산 (길이 2부터 N까지)
       =============================== */
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % MOD;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % MOD;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    /* ===============================
       길이가 N인 계단 수의 총 개수 계산
       =============================== */
    long long result = 0;
    for (int j = 0; j <= 9; j++) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << "\n";
    return 0;
}
