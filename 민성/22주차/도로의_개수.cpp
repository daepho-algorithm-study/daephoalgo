#include <iostream>
#include <algorithm>

using namespace std;

// 경우의 수 누적 배열
long long dp[101][101];
// 공사 중인 도로 체크 배열
bool check[101][101][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, a, b, c, d;
    cin >> n >> m >> k;
    // 공사 중인 도로 체크
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c >> d;
        if (a == c)
            check[a][max(b, d)][0] = true;
        else
            check[max(a, c)][b][1] = true;
    }
    // dp 배열 초기값 설정
    dp[0][0] = 1;
    // 세로 시작값 설정
    for (int i = 1; i <= n; i++)
    {
        // 공사 중인 도로를 지나는 경우면 0 기입
        if (!check[i][0][1])
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
    }
    // 가로 시작값 설정
    for (int i = 1; i <= m; i++)
    {
        if (!check[0][i][0])
            dp[0][i] = dp[0][i - 1];
        else
            dp[0][i] = 0;
    }
    // 공사 중인 도로를 지나지 않는 경우의 수 누적
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!check[i][j][0])
                dp[i][j] += dp[i][j - 1];
            if (!check[i][j][1])
                dp[i][j] += dp[i - 1][j];
        }
    cout << dp[n][m];
    return 0;
}