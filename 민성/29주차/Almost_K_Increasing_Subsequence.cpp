#include <iostream>
#include <algorithm>

using namespace std;

// 수열 저장 배열
int sq[500];
// DP 배열 할당
int dp[500][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // 수열 정보 저장
    for (int i = 0; i < n; i++)
        cin >> sq[i];
    // 초기값 갱신
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    // 수열 탐색하면서 DP 배열 누적
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            for (int l = 0; l <= k; l++)
            {
                // 앞쪽보다 뒤쪽이 크거나 같을 때는 1개씩 누적
                if (sq[j] <= sq[i])
                    dp[i][l] = max(dp[i][l], dp[j][l] + 1);
                // 그렇지 않다면 k에서 1 소모 후 누적
                else if (l > 0)
                    dp[i][l] = max(dp[i][l], dp[j][l - 1] + 1);
            }
    // 길이 중 가장 큰 값 저장 변수
    int mx = 0;
    // 최댓값 갱신
    for (int i = 0; i <= k; i++)
        mx = max(mx, dp[n - 1][i]);
    cout << mx;
    return 0;
}