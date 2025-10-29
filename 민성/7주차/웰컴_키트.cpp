#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, p;
    int size[6];
    cin >> n;
    for (int i = 0; i < 6; i++)
        cin >> size[i];
    cin >> t >> p;
    int sm = 0;
    for (int i = 0; i < 6; i++)
        sm += (size[i] + t - 1) / t;
    cout << sm << "\n";
    cout << n / p << " " << n % p;
    return 0;
}