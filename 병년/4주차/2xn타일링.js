function solution(n) {
    var answer = 0;
    // dp 배열 정의
    let dp = new Array(n + 1).fill(0);
    // 계산의 편의성을 위한 초기 값 설정
    dp[0] = 1
    dp[1] = 1
    for (let i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    answer = dp[n]
    return answer;
}