#include <iostream>

using namespace std;

bool np[1000001]; // 소수 판별 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, ans = 1; // 계산값 저장 변수
    cin >> n;
    // 에라토스테네스의 체로 소수 판별
    for (long long i = 2; i * i <= n; i++)
    {
        if (np[i])
            continue; // 해당 수가 소수가 아니면 스킵
        long long k = i * i;
        while (k <= 1000000)
        {
            np[k] = true; // 소수가 아닌 수들 체크
            k += i;       // 배수 체크
        }
    }
    // 오일러의 피 공식을 이용하여 서로소의 수 계산
    for (long long i = 2; i * i <= n; i++)
    {
        if (np[i])
            continue;     // 해당 수가 소수가 아니면 스킵
        long long sq = 1; // 소인수 제곱 저장 변수
        while (n % i == 0)
        {
            sq *= i; // 해당 소인수의 제곱값 저장
            n /= i;
        }
        if (sq > 1)
            ans *= (i - 1) * (sq / i); // φ(p^n) = (p - 1) * p^(n-1);
    }
    if (n != 1)
        ans *= n - 1; // n^(1/2)보다 큰 소인수 처리
    cout << ans;
    return 0;
}