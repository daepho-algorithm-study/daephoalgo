#include <iostream>

using namespace std;

// n의 소인수 체크 배열
bool prime[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 나눔수 할당
    int n, div = 2;
    cin >> n;
    // 에라토스테네스의 체로 소수가 아닌 수들 체크
    for (int i = 2; i * i <= n; i++)
        for (int j = i; j * i <= n; j++)
            prime[i * j] = true;
    // n의 소인수 체크
    int temp = n;
    while (temp != 1)
    {
        // 나눔수가 소인수에 해당하면 체크
        if (temp % div == 0)
        {
            prime[div] = true;
            temp /= div;
        }
        // 아니면 다른 소인수 탐색
        else
            div++;
    }
    // 소수면서 n의 소인수가 아닌 수 출력
    for (int i = 2; i <= n; i++)
        if (!prime[i])
        {
            cout << i;
            return 0;
        }
}