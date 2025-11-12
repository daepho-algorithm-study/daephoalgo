#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // 1은 무조건 최대공약수가 1이므로 n == k 불가능
    if (n == k)
        cout << "Impossible";
    else
        for (int i = 1; i <= n; i++)
        {
            if (i < n - k)
                cout << i + 1; // 1 차이가 나면 최대공약수는 무조건 1
            else if (i == n - k)
                cout << 1; // 1은 최대공약수가 1
            else
                cout << i; // 자기 자신이 Gcd가 되게 설정
            cout << " ";
        }
    return 0;
}