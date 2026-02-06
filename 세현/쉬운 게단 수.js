const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N) {
  // 나머지 연산할 수
  const m = 1000000000;

  // 2차원 dp 배열. N 의 길이의 수를 0~9 의 경우 모두 계산시켜 놓는 것
  const dp = Array.from({length: N+1}, () =>
    Array.from({length: 10}, () => 1) // 1 ~ 9(한 자릿수) 미리 세어놓음
  );

  // 0 은 제외
  dp[1][0] = 0;

  // 자릿수 2개부터 검사
  for (let i = 2; i <= N; i++) {
    // 중요한 포인트는 맨 끝 수이며 뒤에 붙을 수를 결정함
    
    // 맨 끝이 0인 경우 무조건 1이 붙어야 됨
    dp[i][0] = dp[i-1][1] % m;

    //맨 끝이 9인 경우 무조건 8이 붙어야 됨
    dp[i][9] = dp[i-1][8] % m;

    // 맨 끝이 1~8 사이면 d-1 이 올 수도, d+1이 올 수도 있음
    for (let j = 1; j < 9; j++) {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % m;
    }
  }

  // 총 경우의 수
  let cnt = 0;

  // 마지막 자리의 경우의 수를 계산
  for (let i = 0; i < 10; i++) {
    cnt = (cnt + dp[N][i]) % m;
  }
  return cnt;
}

console.log(solution(input[0]));
