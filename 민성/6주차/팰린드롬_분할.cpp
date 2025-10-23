#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool palindrom[2500][2500]; // 팰린드롬 여부 체크 배열
int dp[2500];               // 분할 최솟값 저장 배열
int INF = 1e9;              // 초기화 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int ln = s.size(); // 문자열 길이 저장
    for (int i = 0; i < ln; i++)
    {
        dp[i] = INF;            // 배열 초기화
        palindrom[i][i] = true; // 한 칸 짜리 팰린드롬 체크
    }
    for (int i = 0; i < ln - 1; i++)
        if (s[i] == s[i + 1])
            palindrom[i][i + 1] = true; // 두 칸 짜리 팰린드롬 체크
    for (int i = ln - 3; i >= 0; i--)
        for (int j = i + 2; j < ln; j++)
            if (s[i] == s[j] && palindrom[i + 1][j - 1])
                palindrom[i][j] = true; // 세 칸 이상 팰린드롬 체크
    for (int i = 0; i < ln; i++)
    {
        if (palindrom[0][i])
        {
            dp[i] = 1; // 해당 길이 전체가 팰린드롬이면 1 체크 후 스킵
            continue;
        }
        for (int j = 1; j <= i; j++)
            if (palindrom[j][i])
                // i번 까지의 분할 최소 탐색
                dp[i] = min(dp[i], dp[j - 1] + 1);
    }
    cout << dp[ln - 1];
    return 0;
}