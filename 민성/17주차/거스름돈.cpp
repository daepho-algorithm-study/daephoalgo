#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 동전 개수 저장 변수 할당
    int n, coin = 0;
    cin >> n;
    // 액수가 5의 배수가 될 때까지 2원 동전 추가
    while (n > 0 && n % 5 != 0)
    {
        n -= 2;
        coin++;
    }
    // 거슬러 줄 수 없으면 -1 출력
    if (n % 5 != 0)
    {
        cout << -1;
        return 0;
    }
    // 나머지 액수 5원 동전으로 계산
    coin += n / 5;
    cout << coin;
    return 0;
}