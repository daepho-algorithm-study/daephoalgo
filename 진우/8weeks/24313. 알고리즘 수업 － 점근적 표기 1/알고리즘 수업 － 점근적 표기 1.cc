#include <iostream>
using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    // O(n) 조건을 위해 두 가지 검사
    if (a1 * n0 + a0 <= c * n0 && a1 <= c) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
