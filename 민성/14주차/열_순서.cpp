#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    // 문자열 길이 저장
    int ln = s.size();
    // 26진수 자리 곱셈 저장 변수와 정답 저장 변수
    long long num = 1, ans = 0;
    // 문자열 뒤부터 계산
    for (int i = ln - 1; i >= 0; i--)
    {
        ans += 1LL * (s[i] - 64) * num;
        num *= 26;
    }
    cout << ans;
    return 0;
}