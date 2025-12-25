#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, t;
    cin >> l;
    t = l / 5;
    // 나머지가 존재하면 t값 1 증가
    if (l % 5)
        t++;
    cout << t;
    return 0;
}