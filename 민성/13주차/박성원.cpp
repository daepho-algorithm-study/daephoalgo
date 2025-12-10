#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b); // 최대 공약수 계산 함수
string perm[15];                         // 정수 저장 배열
// 선택한 정수 집합을 가르키는 비트마스킹과 나머지가 정보가 저장된 dp배열
long long dp[32768][100];
// 10^k(0 <= k < 50) 나머지 저장 배열과 정수 나머지 저장 배열
int d[51], num[15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> perm[i]; // 정수 저장
    cin >> k;
    d[0] = 1; // 1을 k로 나눈 나머지 값 저장
    for (int i = 1; i <= 50; i++)
        d[i] = (d[i - 1] * 10) % k; // (a*10) mod = (a mod) * (10 mod)
    for (int i = 0; i < n; i++)
    {
        int ln = perm[i].size(); // 정수 길이 저장
        for (int j = 0; j < ln; j++)
        {
            int ones = (perm[i][j] - '0') % k;    // 숫자 할당
            num[i] += (ones * d[ln - j - 1]) % k; // 해당 자리수의 나머지값 합산
            num[i] %= k;
        }
    }
    dp[0][0] = 1; // 초기 상태 설정
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                continue; // 이미 사용한 원소면 스킵
            for (int mod = 0; mod < k; mod++)
            {
                if (!dp[i][mod])
                    continue;            // 가능한 경우의 수가 없으면 스킵
                int ln = perm[j].size(); // 선택한 원소 길이 저장
                // 선택 원소를 뒤에 추가했을 때 생성된 순열 나머지 계산
                int nxt = ((d[ln] * mod) % k + num[j]) % k;
                // 해당 집합을 선택할 경우의 수 합산
                dp[i | (1 << j)][nxt] += dp[i][mod];
            }
        }
    }
    long long p = dp[(1 << n) - 1][0], q = 1; // 정답 순열 개수 저장
    for (int i = 2; i <= n; i++)
        q *= i;                // n!값 저장
    long long div = gcd(p, q); // 최대공약수 할당
    cout << p / div << "/" << q / div;
    return 0;
}

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a); // 유클리드 호제법 사용
}