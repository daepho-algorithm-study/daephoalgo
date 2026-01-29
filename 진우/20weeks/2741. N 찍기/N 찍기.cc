#include <iostream>

using namespace std;

int main() {
    int N;              // 출력할 숫자의 개수
    cin >> N;           // 정수 N 입력

    // 1부터 N까지 순서대로 출력
    for (int i = 1; i <= N; i++) {
        cout << i << "\n";   // 현재 숫자 출력 후 줄바꿈
    }

    return 0;           // 프로그램 정상 종료
}
