#include <iostream>

using namespace std;

int C[53][53];   // 조합 경우의 수 저장 배열
int MOD = 10007; // 나눔 수 할당

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sm = 0; // 경우의 총 합산 저장 변수
    cin >> n;
    for (int i = 0; i <= 52; i++)
    {
        C[i][0] = 1; // nC0과 nCn값 할당
        C[i][i] = 1;
    }
    // 파스칼의 삼각형으로 조합 경우의 수 계산
    for (int i = 2; i <= 52; i++)
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    for (int i = 1; i <= n / 4; i++)
    {
        // 포 카드가 나왔을 때 경우의 수 계산
        int temp = C[13][i] * C[52 - i * 4][n - i * 4] % MOD;
        if (i % 2 == 1) // 포카드가 홀수 번 나온 경우는 합산
            sm = (sm + temp) % MOD;
        else // 포카드가 짝수 번 나온 경우는 차감
            sm = (sm - temp + MOD) % MOD;
    }
    cout << sm;
    return 0;
}