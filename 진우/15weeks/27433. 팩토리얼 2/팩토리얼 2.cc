#include <iostream>   // 입출력(cin, cout)을 사용하기 위한 헤더

using namespace std;  // std:: 생략을 위한 네임스페이스 사용

// 정수 a의 팩토리얼을 계산하는 재귀 함수
long long factorial(int a) {
    // 종료 조건: 0!은 1
    if (a == 0) {
        return 1;
    }

    // 재귀 호출
    // a! = a × (a-1)!
    return a * factorial(a - 1);
}

int main() {
    int N;            // 팩토리얼을 계산할 정수
    cin >> N;         // 사용자로부터 입력 받기

    // 팩토리얼 계산 결과 출력
    cout << factorial(N) << "\n";

    return 0;         // 프로그램 정상 종료
}
