#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, k;
    cin >> m >> k;
    if (m % k == 0)
        cout << "Yes"; // 나머지가 없으면 Yes 출력
    else
        cout << "No"; // 나머지가 존재하면 No 출력
    return 0;
}