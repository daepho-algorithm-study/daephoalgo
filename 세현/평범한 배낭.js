const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  // .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, K, stuff) {

  // dp[i][j] =
  // i번째 물건까지 고려했을 때
  // 무게 j에서의 최대 가치
  const dp = Array.from({length: N+1}, () =>
    Array.from({length: K+1}, () => 0)
  );

  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= K; j++) {

      // 현재(i번째) 물건 무게가 허용 무게보다 작거나 같으면
      if (stuff[i-1][0] <= j) {

        // 넣는 경우와 안 넣는 경우를 비교해서 큰 값을 기록
        dp[i][j] = Math.max(
          dp[i-1][j - stuff[i-1][0]] + stuff[i-1][1], // 넣는 경우
          dp[i-1][j]                                  // 안 넣는 경우
        );

      // 못 넣으면
      } else {

        // 이전 값 그대로 들고옴
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  // 최대 가치 반환
  return dp[N][K];
}
console.log(solution(input[0][0], input[0][1], input.slice(1)));
