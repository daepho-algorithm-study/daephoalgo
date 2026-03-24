#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// 뒤집힌 문자열 출력 함수
string rev(long long num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    // 2 제곱값과 제곱수 저장 변수
    long long p = 4, n = 1;
    cin >> m;
    // 팰린드롬을 포함하는 최소 자릿수 탐색(중앙 기준으로 분리 후 생긴 자릿수)
    while (p - 2 < m)
    {
        p *= 2;
        n++;
    }
    // 2의 제곱 임시 변수 및 뒤집을 수 저장 변수 할당
    long long sq = pow(2, n), temp = sq / 2;
    // 아래 자릿수 경우의 수 차감
    m -= sq - 2;
    // 숫자로 변환할 이진수 문자열 저장 변수
    string b;
    // 홀수 길이에 해당하는 지 판별(홀수면 중간 수를 공유)
    if (m <= sq / 2)
    {
        temp += m - 1;
        // 역방향 문자열 임시 저장
        b = rev(temp);
        // 역방향 문자열 저장 변수 할당
        string rb = b;
        // 정방향으로 전환
        reverse(b.begin(), b.end());
        // 중앙 수 제외 후 이어붙이기
        b += rb.substr(1);
    }
    else
    {
        temp += m - sq / 2 - 1;
        b = rev(temp);
        string rb = b;
        reverse(b.begin(), b.end());
        // 모두 이어붙이기
        b += rb;
    }
    // 문자열 숫자로 변환
    long long ans = 0;
    p = 1;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '1')
            ans += p;
        p *= 2;
    }
    cout << ans;
    return 0;
}

string rev(long long num)
{
    string s;
    // 숫자를 뒤집힌 이진수 형태로 변환
    while (num > 0)
    {
        s += to_string(num % 2);
        num /= 2;
    }
    return s;
}