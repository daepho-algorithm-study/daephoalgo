#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;
    // 각 축의 거리 차이 합 계산
    int dif = abs(a - c) + abs(b - d);
    // 목적지까지 도달 가능하고, 목적지까지 최소 이동으로 도착 후 이동 가능 횟수가 짝수면 가능
    if (t >= dif && (t - dif) % 2 == 0)
        cout << "Y";
    else
        cout << "N";
    return 0;
}