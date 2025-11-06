#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--)
    {
        int sm = 0; // 카드 수 전체 합 저장 변수
        cin >> n;
        vector<int> card(n); // 카드에 적힌 수 저장 배열
        // dp 배열 할당
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> card[i]; // 카드 수 저장
            sm += card[i];  // 카드 수 합산
        }
        for (int i = 0; i < n; i++)
            dp[i][i] = card[i]; // 초기값 할당
        for (int len = 2; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                // 왼쪽과 오른쪽을 골랐을 때 두 명의 점수 차이값 중 큰 값 삽입
                dp[i][j] = max(card[i] - dp[i + 1][j], card[j] - dp[i][j - 1]);
            }
        int mx = dp[0][n - 1]; // 최대 점수 차이
        cout << (sm + mx) / 2 << "\n";
    }
    return 0;
}