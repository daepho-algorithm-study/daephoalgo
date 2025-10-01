#include <iostream>

using namespace std;
using ll = long long;

ll mul(ll x, int k); // 제곱 수를 계산하기 위한 함수 정의
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    ll n, s, md, sm = 0; // 역원 및 기댓값 합 저장 변수
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n >> s;
        md = mul(n, mod - 2); // 역원 계산
        sm += (s * md) % mod; // 기댓값 합산
        sm %= mod;
    }
    cout << sm;
    return 0;
}

ll mul(ll x, int k)
{
    if (k == 0)
        return 1; // x의 0승은 1 return
    int mid = k / 2;
    ll ml = mul(x, mid) % mod; // x의 k/2제곱을 계산
    ml = (ml * ml) % mod;      // x의 k/2제곱의 2제곱을 계산
    if (k % 2 == 1)            // k가 홀수면 x를 한 번 더 곱셈
        ml = (ml * x) % mod;
    return ml;
}
