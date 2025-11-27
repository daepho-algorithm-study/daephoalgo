#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, quot, mod;
    cin >> n >> t;
    quot = (t - 1) / (n * 2 - 1); // 몫 계산
    mod = (t - 1) % (n * 2 - 1);  // 나머지 계산
    if (quot % 2 == 0)
        cout << mod + 1; // 몫이 짝수면 정방향
    else
        cout << n * 2 - mod; // 몫이 홀수면 역방향
    return 0;
}