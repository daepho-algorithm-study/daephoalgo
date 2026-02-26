#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    long long a, b;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        // b가 2a보다 크면서 a의 배수이면 조건 성립
        if (b >= a * 2 && b % a == 0)
            cout << 1;
        else
            cout << 0;
        cout << "\n";
    }
    return 0;
}