const solution = (n) => {
  var answer = 0;
  const dp = Array.from({ length: 5001 }, () => 0);

  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;

  for (let i = 5; i <= n; i++) {
    if (i % 2 === 1) dp[i] = 0;
    else {
        let result = 0
        let next = i
        while (next > 0) {
            let prev = dp[next - 2];
            result += prev ** 2 +  next / 2;
            next = next - 2
        }
        dp[i] = result
    }
  }
  answer = dp[n] % 10000000007;
  return answer;
};
