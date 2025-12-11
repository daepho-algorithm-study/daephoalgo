#include <iostream>

using namespace std;

long long A(int h, int m, int t); // 고도 계산 함수 정의

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, m;
    cin >> h >> m;
    for (int i = 1; i <= m; i++)
        if (A(h, m, i) <= 0) // 땅에 닿았으면 시간 출력 후 종료
        {
            cout << "The balloon first touches ground at hour: " << i;
            return 0;
        }
    // M초 동안 땅에 닿지 못했으면 아래 문구 출력
    cout << "The balloon does not touch ground in the given time.";
    return 0;
}

long long A(int h, int m, int t)
{
    long long t2 = t * t; // t^2값 저장 변수
    return (-6) * t2 * t2 + h * t2 * t + 2 * t2 + t;
}