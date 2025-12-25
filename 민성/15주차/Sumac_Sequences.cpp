#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    // 수열 길이 저장 변수
    int ln = 2;
    cin >> a >> b;
    // a가 b보다 작아질 때까지 반복
    while (a >= b)
    {
        // 다음 수열 할당
        int temp = b;
        b = a - b;
        a = temp;
        // 수열 길이 증가
        ln++;
    }
    cout << ln;
    return 0;
}