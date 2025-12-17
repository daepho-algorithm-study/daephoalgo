#include <iostream>
using namespace std;

int main() {
    int T; 
    cin >> T; // 테스트 케이스 개수 입력

    for (int i = 0; i < T; i++) { // 각 테스트 케이스에 대해 반복
        int N, M;
        cin >> N >> M; // 조합 계산을 위한 N, M 입력 (M개의 항목 중 N개 선택)

        long long dp[31] = { 0 }; // dp[j]는 j개를 선택하는 조합의 수 저장 (최대 30까지)
        dp[0] = 1;  // 0개 선택(nC0) 경우의 수는 항상 1

        // M개의 항목을 순서대로 고려하며 조합 계산
        for (int i = 1; i <= M; i++) {
            // 뒤에서부터 업데이트하여 이전 단계의 값을 덮어쓰지 않도록 함
            for (int j = i; j >= 1; j--) {
                dp[j] = dp[j] + dp[j - 1]; 
                // dp[j] : i-1개 항목에서 j개 선택한 경우
                // dp[j-1] : i-1개 항목에서 j-1개 선택한 경우
                // i번째 항목을 포함하지 않는 경우 + 포함하는 경우
            }
        }

        cout << dp[N] << "\n"; // M개 중 N개를 선택하는 조합의 수 출력
    }
    return 0;
}
