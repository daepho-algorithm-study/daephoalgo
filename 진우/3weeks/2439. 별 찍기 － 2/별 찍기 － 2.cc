#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i; j++) cout << ' '; // 공백 출력
        for (int j = 0; j < i; j++) cout << '*';     // 별 출력
        cout << '\n';
    }
    return 0;
}
