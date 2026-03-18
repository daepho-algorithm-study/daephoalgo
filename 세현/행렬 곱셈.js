const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, M, K, A, B) {
  const result = Array.from({length: N}, () =>
    Array.from({length: K}, () => 0)
  );

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < K; j++) {
      for (let k = 0; k < M; k++) {
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return result.map((line) => line.join(" ")).join("\n");
}

const [N, M] = input[0].split(" ").map(Number);
const A = input.slice(1, N+1).map((line) => line.split(" ").map(Number));
const K = Number(input[N+1].split(" ")[1]);
const B = input.slice(N+2).map((line) => line.split(" ").map(Number));
console.log(solution(N, M, K, A, B));
