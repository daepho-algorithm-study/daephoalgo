#include <iostream>

using namespace std;

// 문제에서 제시한 나눔 수
int mod = 16769023;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정답 저장 변수
    int n, ans = 2;
    cin >> n;
    // 길이가 홀수일 때(1 제외) 두 배씩 경우의 수 증가
    for (int i = 2; i < n; i += 2)
        ans = (ans * 2) % mod;
    cout << ans;
    return 0;
}