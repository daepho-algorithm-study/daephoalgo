const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, times) {
  let answer = 0;
  times.sort((a, b) => a - b);
  for (let i = 0; i < N; i++) {
    answer += times[i] * (N-i);
  }

  return answer;
}

console.log(solution(input[0][0], input[1]));
