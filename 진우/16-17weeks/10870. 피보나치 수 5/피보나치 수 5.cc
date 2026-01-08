#include <iostream>  

using namespace std; 

// 피보나치 수를 재귀적으로 계산하는 함수
int fun(int a) {
    // 종료 조건 1: a가 0이면 0 반환
    if (a == 0) {
        return 0;
    }

    // 종료 조건 2: a가 1이면 1 반환
    if (a == 1) {
        return 1;
    }
    
    // 재귀 호출
    // fun(a-1)과 fun(a-2)를 호출하여
    // 두 결과를 더한 값을 반환
    return fun(a - 1) + fun(a - 2);
}

int main() {
    int N;
    cin >> N;        // 피보나치 수를 구할 정수 N 입력

    // N번째 피보나치 수 출력
    cout << fun(N) << "\n";

    return 0;        // 프로그램 정상 종료
}
