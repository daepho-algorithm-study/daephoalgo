#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort 사용
using namespace std;

int main() {
    while (true) {
        int A, B;
        cin >> A >> B;
        if (A == 0 && B == 0) {
            break;
        }
        int sum = A + B;
        cout << sum << endl;
    }
}
