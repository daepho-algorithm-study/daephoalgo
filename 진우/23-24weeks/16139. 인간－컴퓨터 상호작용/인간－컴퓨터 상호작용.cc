#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 

    string S;
    cin >> S;                          // 문자열 입력
    int n = S.size();                  // 문자열 길이

    // dp[문자][인덱스] 배열 생성
    // dp[c][i] = 0 ~ i-1 까지 문자 c가 등장한 횟수
    vector<vector<int>> dp(26, vector<int>(n + 1, 0));

    // 각 알파벳 문자(c)별로 누적 합 계산
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < n; i++) {
            dp[c][i + 1] = dp[c][i];   // 이전까지 누적값 그대로 복사

            // 현재 문자 S[i]가 c와 같으면 +1
            if (S[i] - 'a' == c) {
                dp[c][i + 1]++;
            }
        }
    }
    // 이제 dp[c][i]는 0~i-1까지 문자 c의 개수가 저장됨

    int q;
    cin >> q;  // 쿼리 개수

    // 각 쿼리 처리
    for (int i = 0; i < q; i++) {
        char c; // 찾고 싶은 문자
        int l, r; // 구간 [l, r]
        cin >> c >> l >> r;

        int idx = c - 'a'; // 문자를 0~25 인덱스로 변환

        // [l, r] 구간에서 문자 c의 개수 = dp[r+1] - dp[l]
        // dp 배열은 0 ~ i-1까지 누적합이므로, r+1을 사용
        cout << dp[idx][r + 1] - dp[idx][l] << "\n";
    }

    return 0;
}
