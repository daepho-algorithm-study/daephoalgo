const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(""));

// console.log(input);

function solution(str1, str2) {

  const N = str1.length, M = str2.length;

  // dp[i][j] =
  // str1 앞 i글자
  // str2 앞 j글자의 LCS 길이
  const dp = Array.from({length: N+1}, () =>
    Array.from({length: M+1}, () => 0)
  );

  // 1부터 시작
  // 0행, 0열은 문자열 길이 0인 경우
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= M; j++) {

      // 현재 문자가 같으면
      if (str1[i-1] === str2[j-1]) {

        // 둘 다 한 글자 소비
        // 대각선 + 1
        dp[i][j] = dp[i-1][j-1] + 1;

      } else {

        // 다르면
        // 위(하나 버림) vs 왼쪽(하나 버림)
        dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  // 전체 문자열 기준 LCS 길이
  return dp[N][M];
}

console.log(solution(input[0], input[1]));
