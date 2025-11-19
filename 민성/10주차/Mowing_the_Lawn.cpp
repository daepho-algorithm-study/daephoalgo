#include <iostream>
#include <deque>

using namespace std;

long long efc(int x); // 최대 효율 계산 함수 정의
// 소 효율 저장 배열과 누적합 배열, dp 배열
long long cow[100001], psum[100001], dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> cow[i]; // 소 효율 저장
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + cow[i]; // 누적합 저장
    deque<int> dq;                      // 소 번호 저장 덱
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && efc(dq.back()) <= efc(i))
            dq.pop_back(); // 현재 위치까지의 효율보다 낮은 효율 제외
        while (!dq.empty() && dq.front() < i - k)
            dq.pop_front(); // 범위 밖 번호는 제외
        dq.push_back(i);
        dp[i] = psum[i] + efc(dq.front()); // 최대 효율 할당
        // i가 k보다 작으면 efc처리가 오히려 손해므로 누적합이랑 크기 비교
        if (i <= k)
            dp[i] = max(dp[i], psum[i]);
    }
    cout << dp[n];
    return 0;
}

long long efc(int x)
{
    // dp 배열 점화식 dp[i] = max(psum[i] - psum[j] + dp[j - 1])
    return dp[x - 1] - psum[x];
}