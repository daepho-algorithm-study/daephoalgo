#include <iostream>
#include <algorithm>

using namespace std;

int sticker[2][100000]; // 스티커 점수 저장 배열
int dp[2][100000];      // dp를 활용할 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++)
                cin >> sticker[j][k];
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = dp[1][0] + sticker[0][1]; // dp 초기값 갱신
        dp[1][1] = dp[0][0] + sticker[1][1];
        for (int j = 2; j < n; j++)
        {
            dp[0][j] = max({dp[1][j - 1], dp[0][j - 2], dp[1][j - 2]}) + sticker[0][j];
            // 바로 전 칸 대각선 방향과 전전 칸 2개를 비교하여 큰 수를 저장
            dp[1][j] = max({dp[0][j - 1], dp[0][j - 2], dp[1][j - 2]}) + sticker[1][j];
        }
        cout << max({dp[0][n - 1], dp[1][n - 1], dp[0][n - 2], dp[1][n - 2]}) << "\n";
        // 제일 끝에서 위 아래 2칸씩 4칸 중 가장 큰 수 출력
    }

    return 0;
}