#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // N이 짝수면 해당 문자열 출력
    if (n % 2 == 0)
        cout << "I LOVE CBNU";
    // N이 홀수면 심볼 출력
    else
    {
        // 윗 받침 출력
        for (int i = 0; i < n; i++)
            cout << "*";
        // 아래 ㅅ 출력
        for (int k = 0; k <= n / 2; k++)
        {
            cout << "\n";
            for (int i = 0; i < n / 2 - k; i++)
                cout << " ";
            for (int i = 0; i <= k * 2; i++)
            {
                if (i == 0 || i == k * 2)
                    cout << "*";
                else
                    cout << " ";
            }
        }
    }
    return 0;
}