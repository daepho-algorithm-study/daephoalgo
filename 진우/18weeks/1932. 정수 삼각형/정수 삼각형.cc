#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][j] : i번째 줄 j번째 숫자까지 내려왔을 때의 최대 누적 합
int dp[501][501] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;   // 삼각형의 높이 입력

    // 삼각형 숫자 입력
    // dp 배열에 그대로 저장
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    // DP 계산
    // 두 번째 줄부터 시작
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            // 왼쪽 위(dp[i-1][j-1])와 오른쪽 위(dp[i-1][j]) 중 큰 값 선택
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    // 마지막 줄에서 최대값 찾기
    int mx = -999999;   // 충분히 작은 값으로 초기화

    for (int i = 1; i <= N; i++) {
        if (mx < dp[N][i]) {
            mx = dp[N][i];
        }
    }

    // 결과 출력
    cout << mx << "\n";
    
    return 0;
}
