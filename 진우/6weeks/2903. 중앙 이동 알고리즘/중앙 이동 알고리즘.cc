#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int side = 1;
    for (int i = 0; i < N; i++) {
        side *= 2;
    }
    side += 1;

    cout << side * side << "\n";
}
