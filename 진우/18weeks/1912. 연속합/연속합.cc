#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;   // 수열의 길이 입력

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // 수열 원소 입력
    }

    // dp[i] = i번째 원소에서 끝나는 최대 연속 부분합
    vector<long long> dp(n);

    // 첫 번째 원소로 초기화
    dp[0] = arr[0];

    // 전체 최대 연속합을 저장하는 변수
    long long mx = dp[0];

    // 두 번째 원소부터 차례대로 dp 계산
    for (int i = 1; i < n; i++) {
        // 이전까지의 합에 현재 값을 더할지,
        // 아니면 현재 값부터 새로 시작할지 선택
        if (dp[i - 1] + arr[i] > arr[i]) {
            dp[i] = dp[i - 1] + arr[i];   // 이어서 더하는 게 더 큰 경우
        }
        else {
            dp[i] = arr[i];              // 새로 시작하는 게 더 큰 경우
        }

        // 지금까지 나온 최대값 갱신
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    // 최종 최대 연속 부분합 출력
    cout << mx << "\n";

    return 0;
}
