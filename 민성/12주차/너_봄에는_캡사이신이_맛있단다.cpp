#include <iostream>
#include <algorithm>

using namespace std;

long long square(int n);            // 2의 N승 계산 함수
int scobil[300000];                 // 스코빌 지수 저장 배열
long long sm = 0, MOD = 1000000007; // 고통지수 합 저장 변수와 나눔 수 할당

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> scobil[i];     // 스코빌 지수 저장
    sort(scobil, scobil + n); // 오름차순 정렬
    // 정렬된 자리 기준으로(시작점은 1) k자리 스코빌 지수는
    // pow(2, k - 1) - 1번 더해지고 pow(2, N - k) - 1번 빼진다.
    for (int i = 0; i < n; i++)
    {
        sm += (scobil[i] - scobil[n - i - 1]) * (square(i) - 1);
        sm %= MOD;
    }
    cout << sm;
    return 0;
}

long long square(int n)
{
    if (n == 0)
        return 1;                         // 2의 0승은 1
    long long half = square(n / 2) % MOD; // 2의 n/2승 값 저장
    if (n % 2 == 1)
        return 2 * half * half % MOD; // n이 홀수면 2 추가로 곱셈
    else
        return half * half % MOD; // n이 짝수면 제곱만 계산
}
