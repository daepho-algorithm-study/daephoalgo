#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // 공백을 먼저 n - i개 만큼 출력
        for (int j = 0; j < n - i; j++)
            cout << " ";
        // 별을 2i - 1개 만큼 출력
        for (int j = 0; j < i * 2 - 1; j++)
            cout << "*";
        // 줄 바꿈
        cout << "\n";
    }
    return 0;
}