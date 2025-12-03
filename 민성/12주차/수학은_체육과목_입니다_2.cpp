#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, quot, mod, ans; // 몫과 나머지, 정답 저장 변수
    cin >> n;
    quot = (n - 1) / 4, mod = (n - 1) % 4; // 몫, 나머지 저장
    if (quot % 2 == 0)
        ans = mod + 1; // 정방향 순서
    else
        ans = 5 - mod; // 역방향 순서
    cout << ans;
    return 0;
}