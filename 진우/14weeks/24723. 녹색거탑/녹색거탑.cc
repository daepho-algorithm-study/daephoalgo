#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;              // N 입력받기

    int result = 1;        // 결과 변수 초기화

    // result를 2배씩 N번 반복
    for (int i = 1; i <= N; i++) {
        result *= 2;
    }

    cout << result << "\n"; // 결과 출력

    return 0;
}
