#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;          // 정수 N 입력

    // 0!은 1이므로 바로 출력
    if (N == 0) {
        cout << 1 << "\n";
    } 
    else {
        long long result = 1;  // 팩토리얼 결과를 저장할 변수 (초기값 설정)

        // 1부터 N까지 곱해서 N! 계산
        for (int i = 1; i <= N; i++) {
            result *= i;
        }

        cout << result << "\n"; // 결과 출력
    }

    return 0;
}
