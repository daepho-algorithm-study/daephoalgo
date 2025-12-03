#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;  // 창문의 개수 N 입력

    long long cnt = 0;

    // 1^2, 2^2, 3^2 ... i^2 형태로
    // 완전제곱수만 마지막에 창문이 열리게 된다.
    // 따라서 i^2 <= N을 만족하는 i의 개수를 세면 됨.
    for (long long i = 1; i * i <= N; i++) {
        cnt++;  // 조건을 만족하는 i 개수 증가
    }

    // 마지막에 열려 있는 창문의 개수 = N 이하의 완전제곱수 개수
    cout << cnt << "\n";

    return 0;
}
