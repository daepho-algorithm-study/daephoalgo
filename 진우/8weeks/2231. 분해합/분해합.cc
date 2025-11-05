#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int sum = i;
        int M = i;

        while (sum > 0) {
            M += sum % 10;
            sum /= 10;
        }

        if (M == N) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";

    return 0;
}
