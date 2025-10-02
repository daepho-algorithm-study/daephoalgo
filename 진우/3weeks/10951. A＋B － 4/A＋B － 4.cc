#include <iostream>
using namespace std;

int main() {
    int A, B;
    while (cin >> A >> B) { // EOF가 올 때까지 반복
        cout << A + B << '\n';
    }
    return 0;
}
