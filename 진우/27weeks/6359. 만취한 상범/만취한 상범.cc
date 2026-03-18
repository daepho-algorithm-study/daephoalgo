#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++ 입출력 속도 향상
    cin.tie(nullptr);                 // cin과 cout 연결 해제 → 입출력 속도 향상

    int T;
    cin >> T;                         // 테스트 케이스 개수 입력

    // T개의 테스트 케이스 처리
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;                     // n 입력 (창문의 개수)

        int cnt = 0;                  // 최종적으로 열려 있는 창문의 개수

        // i*i ≤ n 인 동안 반복
        // 즉 n 이하의 완전제곱수 개수를 세는 과정
        for (int i = 1; i * i <= n; i++) {
            cnt++;                    // 완전제곱수 발견 → 카운트 증가
        }

        // 결과 출력
        cout << cnt << "\n";
    }

    return 0;
}