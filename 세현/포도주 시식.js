const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, wines) {

  // 와인 개수가 2개 이하면 전체 합이 답임
  if (N < 2) {
    return wines.reduce((a, b) => a+b);
  }

  // 1차원 dp(memo) 배열
  // 인덱스 -> i번째 와인까지 고려했을 때 마실 수 있는 최대 포도주 양
  const dp = Array.from({length: N}, () => 0);

  // 와인 1개의 최대값
  dp[0] = wines[0];

  //와인 2개의 최대값
  dp[1] = wines[0] + wines[1];

  //와인 3개의 최대값 ([1번 2번], [1번 3번], [2번 3번] 중 최대를 선택)
  dp[2] = Math.max(wines[0]+wines[1], wines[0]+wines[2], wines[1]+wines[2]);

  // 와인 N개의 최대값
  // 3개 연속을 피해서 이전의 최대 값을 가져오는 것임
  for (let i = 3; i < N; i++) {
    dp[i] = Math.max(
        dp[i-1], // i 번째를 안마시는 경우
        dp[i-2]+wines[i], // i-1번째를 안마시는 경우
        dp[i-3]+wines[i-1]+wines[i] // i-2번째를 안마시는 경우
    );
  }

  return dp[N-1];
}

console.log(solution(input[0], input.slice(1)));
