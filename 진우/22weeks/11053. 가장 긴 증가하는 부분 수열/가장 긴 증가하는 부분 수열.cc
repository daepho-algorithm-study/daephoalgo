#include <iostream>   // 입출력 스트림 사용

using namespace std;

int A[1001];          // 입력 수열을 저장하는 배열
int dp[1001];         // i번째까지 끝나는 LIS 길이를 저장하는 배열

int main() {
    ios_base::sync_with_stdio(false);  // cin/cout 속도 최적화
    cin.tie(nullptr);                 // cin과 cout 묶음 해제하여 입출력 속도 향상

    int N;
    cin >> N;                         // 수열의 길이 입력

    for (int i = 0; i < N; i++) {
        cin >> A[i];                  // 수열 요소 입력
    }

    // dp 계산
    for (int i = 0; i < N; i++) {
        dp[i] = 1;                    // 최소 LIS 길이 = 1 (자기 자신만 포함)

        // i번째 이전의 모든 원소와 비교
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {        // 증가 조건: i가 j보다 크면
                dp[i] = max(dp[i], dp[j] + 1);  // j에서 끝나는 LIS에 i를 붙인 길이와 현재 dp[i] 비교
            }
        }
    }

    int mx = -1;                       // LIS 최대 길이 저장 변수
    for (int i = 0; i < N; i++) {
        if (mx < dp[i]) mx = dp[i];   // dp 배열 중 가장 큰 값 찾기
    }

    cout << mx << "\n";                // LIS 길이 출력

    return 0;                          // 프로그램 종료
}
