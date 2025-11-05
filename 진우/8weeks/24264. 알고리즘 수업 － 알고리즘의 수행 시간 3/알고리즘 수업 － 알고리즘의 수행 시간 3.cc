#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << n * n << "\n"; // 수행 횟수 (O(n^2))
    cout << 2 << "\n";     // 수행 시간의 차수 → 2차

    return 0;
}
