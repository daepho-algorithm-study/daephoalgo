#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (1)
    {
        cin >> n >> m;
        // 0 0 이 들어오면 반복 종료
        if (n == 0 && m == 0)
            break;
        // 캔디 정보 저장 배열과 DP 배열 할당
        vector<vector<int>> cdy(n, vector<int>(m)), dp(n, vector<int>(m));
        // 캔디 정보 저장
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> cdy[i][j];
        // 가로줄 한 줄씩 누적
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = cdy[i][0];
            // M의 값에 따라 분기 처리
            if (m >= 2)
                dp[i][1] = cdy[i][1];
            if (m >= 3)
            {
                dp[i][2] = cdy[i][2] + dp[i][0];
                for (int j = 3; j < m; j++)
                    dp[i][j] = max(dp[i][j - 2], dp[i][j - 3]) + cdy[i][j];
            }
        }
        // 가로 누적값을 이용하여 세로 누적
        if (n > 2)
        {
            // M값에 따라 분기 처리
            if (m == 1)
            {
                int mx = dp[0][0];
                dp[2][0] += mx;
                for (int i = 3; i < n; i++)
                {
                    int mxv = max(dp[i - 2][0], dp[i - 3][0]);
                    dp[i][0] += mxv;
                }
            }
            else
            {
                int mx = max(dp[0][m - 1], dp[0][m - 2]);
                dp[2][m - 1] += mx;
                dp[2][m - 2] += mx;
                for (int i = 3; i < n; i++)
                {
                    int mxv = max({dp[i - 2][m - 1], dp[i - 2][m - 2],
                                   dp[i - 3][m - 1], dp[i - 3][m - 2]});
                    dp[i][m - 1] += mxv;
                    dp[i][m - 2] += mxv;
                }
            }
        }
        // N과 M이 1일 경우 예외 처리
        int mx;
        if (n == 1)
        {
            if (m == 1)
                mx = dp[0][0];
            else
                mx = max(dp[0][m - 1], dp[0][m - 2]);
        }
        else
        {
            if (m == 1)
                mx = max(dp[n - 2][0], dp[n - 1][0]);
            else
                mx = max({dp[n - 2][m - 1], dp[n - 2][m - 2], dp[n - 1][m - 1], dp[n - 1][m - 2]});
        }
        cout << mx << '\n';
    }
    return 0;
}