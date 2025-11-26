#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    if (n < k || m < k)
        cout << "Impossible";
    else
    {
        cout << "Possible" << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j && i < k)
                    cout << "*";
                else
                    cout << ".";
            }
            cout << "\n";
        }
    }
    return 0;
}