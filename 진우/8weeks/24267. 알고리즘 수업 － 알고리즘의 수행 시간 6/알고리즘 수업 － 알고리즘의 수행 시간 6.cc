#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << n * (n - 1) * (n - 2) / 6 << "\n"; // 수행 횟수
    cout << 3 << "\n";                          // 시간 복잡도 차수

    return 0;
}
