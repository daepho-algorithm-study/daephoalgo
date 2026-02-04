const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N) {
  // 1~N 까지의 수를 인덱스로 둔 배열 만들기
  // 이 배열에서 해당하는 인덱스(수)를 만들기 까지의 연산 수를 저장할 것임
  const dp = Array.from({length: N+1}, () => 0);

  // i(수)를 이전 연산 결과(나누기 3, 나누기 2, 뺴기 1)로부터 가장 작은 값을 가져 오기
  for (let i = 2; i <= N; i++) {
    
    // 2, 3 모두 나누어 떨어 질 때
    if (i % 2 === 0 && i % 3 === 0) {
      dp[i] = Math.min(dp[i/2], dp[i/3], dp[i-1]) + 1;

      // 2로 나누어 떨어지지는 않을 때
    } else if (i % 2 === 0) {
      dp[i] = Math.min(dp[i/2], dp[i-1]) + 1;

      // 3으로 나누어 떨어지지는 않을 때
    } else if (i % 3 === 0) {
      dp[i] = Math.min(dp[i/3], dp[i-1]) + 1;

      // 빼기 1 밖에 못할 때는 이전 것에다가 +1
    } else {
      dp[i] = dp[i-1] + 1;
    }
  }

  // N으로 만드는데 실행한 연산 횟수가 정답이 됨
  return dp[N];
}

console.log(solution(input[0]));
