#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--)
    {
        // 소인수 중 가장 높은 제곱수 저장 변수
        int mx = 0;
        cin >> n;
        for (int p = 2; p * p <= n; p++)
        {
            // 해당 수의 구성 소인수일 때
            if (n % p == 0)
            {
                // 제곱수 저장 변수
                int cnt = 0;
                // 해당 소수로 나눠질 때까지 나누기(소수가 아닌 수는 앞에서 소수의 배수이므로 여기에 포함되서 계산 필요 X)
                while (n % p == 0)
                {
                    n /= p;
                    cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        // n이 매우 큰 소수를 가졌을 경우
        if (n > 1)
            mx = max(mx, 1);
        cout << mx << "\n";
    }
    return 0;
}