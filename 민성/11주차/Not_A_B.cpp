#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        int c = a + b; // a와 b의 합 계산
        if (c >= 50)
            c = 49; // c는 50이하의 숫자
        else
            c++; // a와 b의 합에서 +1
        cout << c << "\n";
    }
    return 0;
}