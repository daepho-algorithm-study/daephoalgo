#include <iostream>   
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;          // 입력될 실수의 개수

    long double total = 0;  // 세제곱 합을 저장할 변수 (long double 사용 → 큰 수 처리 가능)

    long double c;          // 입력값 임시 저장 변수
    for (int i = 0; i < n; i++) {
        cin >> c;              // 실수 입력
        total += c * c * c;    // 각 값의 세제곱을 누적
    }
    
    // 출력 포맷 설정: 고정 소수점, 소수점 10자리까지
    cout << fixed << setprecision(10);
    cout << cbrt(total) << "\n";  // 세제곱합의 세제곱근 계산 후 출력

    return 0;  // 프로그램 정상 종료
}
