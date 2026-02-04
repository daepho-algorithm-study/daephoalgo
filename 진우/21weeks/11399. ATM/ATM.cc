#include <iostream>     
#include <vector>       
#include <algorithm>   

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;           // 사람 수 입력

    vector<int> arr(N);
    // 각 사람이 돈을 인출하는 데 걸리는 시간 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 인출 시간이 짧은 사람부터 처리하기 위해 오름차순 정렬
    sort(arr.begin(), arr.end());

    vector<int> dp(N);
    // 첫 번째 사람의 대기 시간은 자신의 인출 시간
    dp[0] = arr[0];

    // dp[i] = i번째 사람까지의 누적 대기 시간
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    int result = 0;
    // 모든 사람의 대기 시간을 합산
    for (int i = 0; i < dp.size(); i++) {
        result += dp[i];
    }

    // 최소 대기 시간의 총합 출력
    cout << result << "\n";

    return 0;
}
