#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;  // n 입력

        if (n == 0) break;  // 입력이 0이면 종료

        else {
            // 2n 이하의 소수를 판별하기 위한 에라토스테네스의 체
            // 문제 조건에서 n의 최댓값이 123,456이므로 2n의 최댓값은 246,912
            vector<bool> primenum((123456 * 2) + 1, true);

            // 0과 1은 소수가 아님
            primenum[0] = primenum[1] = false;

            // 에라토스테네스의 체 수행
            // 2부터 sqrt(2n) 까지 검사
            for (int i = 2; i * i <= 2 * n; i++) {
                if (primenum[i]) {  // i가 소수라면
                    // i의 배수를 모두 소수가 아니라고 표시
                    for (int j = i * i; j <= 2 * n; j += i) {
                        primenum[j] = false;
                    }
                }
            }

            // (n, 2n] 범위 내의 소수 개수 카운트
            int cnt = 0;
            for (int i = n + 1; i <= 2 * n; i++) {
                if (primenum[i]) {
                    cnt += 1;
                }
            }

            cout << cnt << "\n";  // 개수 출력
        }
    }
    return 0;
}
