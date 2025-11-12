#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
            break;

        int mx = max({ a, b, c });
        int sum = a + b + c - mx;

        if (mx >= sum) {
            cout << "Invalid" << "\n";  // 삼각형 불가능
        }
        else if (a == b && b == c) {
            cout << "Equilateral" << "\n";
        }
        else if (a == b || b == c || a == c) {
            cout << "Isosceles" << "\n";
        }
        else {
            cout << "Scalene" << "\n";
        }
    }

    return 0;
}
