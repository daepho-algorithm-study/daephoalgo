#include <iostream>

using namespace std;

int highestbit(long long x); // 최상위 비트 위치 출력 함수 정의
long long psum(long long x); // 0 - x까지의 1 개수 계산 함수 정의
long long bitsum[61];        // 2의 N제곱 - 1까지의 1의 개수 합 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    for (int i = 1; i <= 60; i++)
        // 2의 N제곱 - 1까지의 1의 개수 합 저장
        bitsum[i] = (1LL << (i - 1)) * i;
    cout << psum(b) - psum(a - 1);
    return 0;
}

int highestbit(long long x)
{
    for (int i = 60; i >= 0; i--)
        if (x & (1LL << i))
            return i; // 최상위 비트 탐색 시 출력
}

long long psum(long long x)
{
    long long sm = 0; // 합 저장 변수
    while (x)
    {
        int k = highestbit(x); // 해당 수의 최상위 비트 할당
        long long temp = 1LL << k;
        // 최상위 비트 전까지의 1의 개수와 최상위 비트에 위치하는 1의 개수 합산
        sm += bitsum[k] + (x - temp + 1);
        x -= temp; // 계산이 다 된 부분은 제거
    }
    return sm;
}