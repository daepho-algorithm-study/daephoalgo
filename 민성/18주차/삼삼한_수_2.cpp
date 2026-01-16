#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    // 3의 거듭제곱 저장 배열 할당
    long long sq[40];
    // 3의 거듭제곱값 저장
    sq[0] = 1;
    for (int i = 1; i < 40; i++)
        sq[i] = sq[i - 1] * 3;
    cin >> n;
    // n이 0인 경우 예외 처리
    if (n == 0)
    {
        cout << "NO";
        return 0;
    }
    // n보다 작거나 같은 거듭제곱값 중 큰 것부터 차감
    int temp = 39;
    while (temp >= 0)
    {
        if (sq[temp] <= n)
            n -= sq[temp];
        temp--;
    }
    if (n == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}