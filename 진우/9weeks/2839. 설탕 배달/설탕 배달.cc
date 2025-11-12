#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 0;

    // N이 0보다 클 때까지 반복
    while (N >= 0) {
        // 5로 나누어떨어지면, 5kg 봉지로 채울 수 있음
        if (N % 5 == 0) {
            cnt += N / 5;  // 남은 설탕을 5로 나눈 몫만큼 봉지 추가
            cout << cnt << "\n";
            return 0;      // 종료
        }
        // 5로 안 나누어지면, 3kg 봉지를 하나 사용
        N -= 3;
        cnt++;
    }

    // 정확히 나눌 수 없는 경우
    cout << -1 << "\n";
    return 0;
}
