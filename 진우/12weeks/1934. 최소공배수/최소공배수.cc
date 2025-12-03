#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;   // 테스트 케이스 개수 입력

    int A, B;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;  // 두 자연수 A와 B 입력

        // A와 B의 최소공배수(LCM)를 구하는 방식
        // 더 작은 수의 배수를 하나씩 증가시키며 체크

        if (A <= B) {
            int i = 1;
            while (true) {
                int result = 0;

                // B의 배수(B * i)가 A로 나누어떨어지면 최소공배수
                if ((B * i) % A == 0) {
                    result = B * i;
                    cout << result << "\n";
                    break;  // 찾았으므로 반복 종료
                }

                i++;  // 배수 증가
            }
        }
        else { // A > B일 때
            int i = 1;
            while (true) {
                int result = 0;

                // A의 배수(A * i)가 B로 나누어떨어지면 최소공배수
                if ((A * i) % B == 0) {
                    result = A * i;
                    cout << result << "\n";
                    break;  // 찾았으므로 반복 종료
                }
                i++;  // 배수 증가
            }
        }
    }

    return 0;
}
