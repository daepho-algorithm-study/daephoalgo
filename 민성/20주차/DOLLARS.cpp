#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 소수점 2자리 출력 고정
    cout.precision(2);
    cout << fixed;
    int n, a;
    // 현재 최고 환율과 최저 환율 저장 변수
    int mx = 0, mn = 0;
    // 현재 보유 달러 저장 변수
    double dollar = 100;
    cin >> n;
    // 환율 정보 입력
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        // 첫 환율 할당
        if (mx == 0)
        {
            mx = a;
            mn = a;
        }
        // 최소 환율이 갱신되지 않을 때까지 탐색
        if (mn >= a)
            mn = a;
        // 최고 환율과 최소 환율 비율만큼 곱 연산
        else
        {
            dollar *= 1.0 * mx / mn;
            mx = a;
            mn = a;
        }
    }
    cout << dollar * mx / mn;
    return 0;
}