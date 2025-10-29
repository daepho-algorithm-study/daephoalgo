#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int sm = 0, idx;
    cin >> s;
    for (int i = 0; i < 12; i++)
    {
        if (s[i] != '*')
            sm += (s[i] - '0') * ((i % 2) * 2 + 1);
        else
            idx = i;
    }
    sm += s[12] - '0';
    sm = (10 - (sm % 10)) % 10;
    if (idx % 2 == 0)
        cout << sm;
    else
    {
        while (sm % 3 != 0)
            sm += 10;
        sm /= 3;
        cout << sm;
    }
    return 0;
}