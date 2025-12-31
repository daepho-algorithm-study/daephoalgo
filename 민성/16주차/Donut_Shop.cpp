#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, e, q;
    char sym;
    cin >> d >> e;
    // e개의 부호 숫자쌍을 d에 계산
    for (int i = 0; i < e; i++)
    {
        cin >> sym >> q;
        // 부호에 따라 계산
        if (sym == '+')
            d += q;
        else
            d -= q;
    }
    cout << d;
    return 0;
}