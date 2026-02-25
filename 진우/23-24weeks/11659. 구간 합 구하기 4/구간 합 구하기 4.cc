#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;    // N: 수의 개수, M: 구간 합을 구할 횟수

    // 원본 배열 (1번 인덱스부터 사용)
    vector<int> arr(N + 1);
    arr[0] = 0;       // 0번 인덱스는 사용하지 않음 (누적 합 계산용)

    // 누적 합 배열
    // dp[i] = arr[1]부터 arr[i]까지의 합
    vector<int> dp(N + 1);
    dp[0] = 0;        // dp[0]은 0으로 초기화

    // 입력을 받으면서 동시에 누적 합 계산
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];               // i번째 값 입력
        dp[i] = dp[i - 1] + arr[i];  // 이전 누적 합 + 현재 값
    }

    int a, b;        // 구간의 시작 인덱스 a, 끝 인덱스 b

    // M개의 구간 합 질의 처리
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;

        // [a, b] 구간 합
        // = (1~b까지의 합) - (1~(a-1)까지의 합)
        cout << dp[b] - dp[a - 1] << "\n";
    }

    return 0;
}
