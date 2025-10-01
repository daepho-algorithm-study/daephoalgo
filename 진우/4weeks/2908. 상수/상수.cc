#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    // 문자열 뒤집기
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    // 문자열을 정수로 변환
    int x = stoi(A);
    int y = stoi(B);

    // 큰 수 출력
    if (x > y) {
        cout << x << endl;
    }
    else {
        cout << y << endl;
    }

    return 0;
}
