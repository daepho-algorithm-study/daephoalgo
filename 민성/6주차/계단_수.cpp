#include <iostream>
#include <cstring>

using namespace std;

long long mod = 1e9;       // 결과값에 나눌 수
long long dp[2][10][1024]; // 마지막 수, 사용된 숫자 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cur = 0; // 현재 누적값 저장 위치
    cin >> n;
    for (int i = 1; i <= 9; i++)
        dp[0][i][1 << i] = 1; // 1자리 수의 경우로 초기화(0은 불가)
    for (int i = 1; i < n; i++)
    {
        int nxt = cur ^ 1;                   // 계산값 저장 위치 할당
        memset(dp[nxt], 0, sizeof(dp[nxt])); // 계산할 공간 초기화
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 1; k < 1024; k++)
            {
                long long temp = dp[cur][j][k]; // 현재까지의 누적 수 할당
                if (temp == 0)
                    continue; // 해당 경우의 수가 존재하지 않으면 스킵
                if (j > 0)    // 해당 수보다 1 낮은 숫자 대입
                {
                    int mark = k | 1 << (j - 1); // 사용할 숫자 마킹
                    dp[nxt][j - 1][mark] += temp;  // 경우의 수 누적
                    dp[nxt][j - 1][mark] %= mod;
                }
                if (j < 9) // 해당 수보다 1 높은 숫자 대입
                {
                    int mark = k | 1 << (j + 1);
                    dp[nxt][j + 1][mark] += temp;
                    dp[nxt][j + 1][mark] %= mod;
                }
            }
        }
        cur = nxt; // 누적값 저장 위치 갱신
    }
    long long sm = 0;
    for (int i = 0; i <= 9; i++)
        sm = (sm + dp[cur][i][1023]) % mod; // 0-9가 모두 사용된 경우만 합산
    cout << sm;
    return 0;
}