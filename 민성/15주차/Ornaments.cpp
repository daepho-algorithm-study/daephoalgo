#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        // n(n+1)/2의 합 = n(n+1)(2n+1)/12 + n(n+1)/4 = n(n+1)(n+2)/6
        cout << k * (k + 1) * (k + 2) / 6 << "\n";
    }
    return 0;
}