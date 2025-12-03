#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;   // 소수를 출력할 구간 [M, N] 입력

    // 에라토스테네스의 체를 위한 배열
    // 크기 1,000,001, 모든 값을 true 로 초기화
    vector<bool> primenum(1000001, true);

    // 0과 1은 소수가 아님
    primenum[0] = primenum[1] = false;

    // 에라토스테네스의 체 수행
    // i * i <= N 까지만 검사해도 충분함
    for (int i = 2; i * i <= N; i++) {
        if (primenum[i]) {   // i가 아직 소수라면
            // i의 배수를 모두 소수가 아니라 false 처리
            // i*i 부터 시작하는 이유: i 이전의 배수들은 이미 처리됨
            for (int j = i * i; j <= N; j += i) {
                primenum[j] = false;
            }
        }
    }

    // M부터 N까지 범위 안에서 소수 출력
    for (int i = M; i <= N; i++) {
        if (primenum[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
