#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);                 

    int N;
    cin >> N;                         // 계단 개수 입력

    // floor[i] : i번째 계단의 점수
    vector<int> floor(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> floor[i];              // 각 계단의 점수 입력
    }

    // dp[i] : i번째 계단까지 올라왔을 때 얻을 수 있는 최대 점수
    vector<int> dp(N + 1, 0);

    // 1번째 계단까지 올라가는 경우
    // → 시작 계단이므로 1번 계단 점수만 얻음
    dp[1] = floor[1];

    // 2번째 계단까지 올라가는 경우
    // → 연속 3계단 금지 규칙을 고려하면
    //    최적 경로는 1번 계단을 밟고 2번 계단으로 이동
    dp[2] = floor[1] + floor[2];

    // 3번째 계단부터 N번째 계단까지 점화식 적용
    for (int i = 3; i <= N; i++) {
        /*
            i번째 계단에 도달하는 경우는 두 가지

            경우 1) i-2 → i
                - i-2 계단에서 두 칸 점프
                - 연속 3계단 금지 조건 OK
                - 점수: dp[i-2] + floor[i]

            경우 2) i-3 → i-1 → i
                - i-3에서 한 칸 점프 → i-1 → i
                - i-1 → i 연속 2계단
                - i-2 건너뜀 → 연속 3계단 금지 조건 OK
                - 점수: dp[i-3] + floor[i-1] + floor[i]

            최종 dp[i]는 두 경우 중 더 큰 값 선택
        */
        dp[i] = max(dp[i - 2] + floor[i], dp[i - 3] + floor[i - 1] + floor[i]);
    }

    // N번째 계단까지 올라갔을 때의 최대 점수 출력
    cout << dp[N] << "\n";

    return 0;
}
