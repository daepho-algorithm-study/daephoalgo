#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 재귀 함수 정의
void rec(long long l, long long r, int c, int n);

// 카드 숫자 저장 배열
int card[18];
// 최댓값 저장 변수
long long mx = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        // 문자열 길이 할당
        int ss = s.size();
        // 카드에 적힌 숫자 저장
        for (int j = 0; j < ss; j++)
        {
            // 6은 모두 9로 전환
            if (s[j] == '6')
                s[j] = '9';
            card[j] = s[j] - '0';
        }
        // 카드 숫자 내림차순 정렬
        sort(card, card + ss, greater<int>());
        // 재귀 탐색
        rec(0, 0, 0, ss);
        cout << mx << "\n";
        mx = 0;
    }
    return 0;
}

void rec(long long l, long long r, int c, int n)
{
    if (c == n)
    {
        // 왼쪽 오른쪽 수 곱셈
        long long mul = l * r;
        // 최대값 갱신
        if (mx < mul)
            mx = mul;
        return;
    }
    // 왼쪽에 수 기입
    rec(l * 10 + card[c], r, c + 1, n);
    // 오른쪽에 수 기입
    rec(l, r * 10 + card[c], c + 1, n);
}