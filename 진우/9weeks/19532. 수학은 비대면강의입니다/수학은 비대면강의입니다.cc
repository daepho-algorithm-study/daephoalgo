#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << " " << y << "\n";
                return 0; // 유일한 해만 존재하므로 바로 종료
            }
        }
    }

    return 0;
}
