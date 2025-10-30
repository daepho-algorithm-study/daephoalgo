#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int i = 1;
    while (N > 1 + 3 * i * (i - 1)) {
        i++;
    }

    cout << i << "\n";
    return 0;
}
