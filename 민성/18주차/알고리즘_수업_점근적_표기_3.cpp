#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, a0, c1, c2, n0;
    cin >> a1 >> a0 >> c1 >> c2 >> n0;
    // f함수값 저장
    int f = a1 * n0 + a0;
    // 빅오 조건 체크
    if (f >= c1 * n0 && f <= c2 * n0)
        cout << 1;
    else
        cout << 0;
    return 0;
}