#include <iostream>

using namespace std;

// 두 자리 소수 저장 배열
int prime[20] = {13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
// 두 자리 소수의 자릿수 차를 11로 나눈 나머지 저장 배열
int dif[20];
// 사용한 소수 개수와 나머지 및 현재 사용 소수 저장 배열
int dp[100001][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
        cout << -1;
    else
    {
        // 소수의 자릿수 차 저장
        for (int i = 0; i < 20; i++)
            dif[i] = (prime[i] / 10 - prime[i] % 10 + 11) % 11;
        // 초기값 설정
        for (int i = 0; i < 20; i++)
            if (!dp[1][dif[i]])
                dp[1][dif[i]] = prime[i];
        // 소수 누적
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < 11; j++)
                // 해당 나머지를 만든 값이 존재할 때만 사용
                if (dp[i - 1][j])
                    for (int k = 0; k < 20; k++)
                    {
                        int idx = (dif[k] + j) % 11;
                        if (!dp[i][idx])
                            dp[i][idx] = prime[k];
                    }
        if (!dp[n][0])
            cout << -1;
        else
        {
            // 인덱스 할당 변수
            int idx = 0;
            for (int i = n; i >= 1; i--)
            {
                // 소수 저장 및 해당 소수 나머지 값 저장
                int p = dp[i][idx], mod = (p / 10 - p % 10 + 11) % 11;
                cout << p;
                // 역추적 인덱스 할당
                idx = (idx - mod + 11) % 11;
            }
        }
    }
    return 0;
}