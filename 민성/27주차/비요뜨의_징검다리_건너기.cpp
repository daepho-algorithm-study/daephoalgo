#include <iostream>

using namespace std;

// 나눔 수 할당
int mod = 1000000007;
// 분할 정복 함수 정의
long long div(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    // t번 반복
    while (t--)
    {
        cin >> n;
        // 출발과 동시에 도착한 경우
        if (n == 1)
            cout << 1;
        else
        {
            // 1번과 N번 징검다리 제외 다른 징검 다리 경우의 수 = 2(건넌다, 안 건넌다)
            long long ans = div(n - 2) % mod;
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}

long long div(int n)
{
    if (n == 0)
        return 1;
    // 반으로 나눠서 계산 후 다시 합산
    long long half = div(n / 2) % mod, one = half * half % mod;
    // n이 짝수면 그대로 출력
    if (n % 2 == 0)
        return one;
    // n이 홀수면 ×2
    else
        return one * 2;
}