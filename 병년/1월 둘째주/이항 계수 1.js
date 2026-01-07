const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

// const solution = (input) => {
//   const [N, K] = input[0].split(" ").map(Number);
//   let parent = N;
//   let child = 1;
//   const recur1 = (n, depth) => {
//     if (depth === K) {
//       return;
//     }
//     parent = parent * n;
//     recur1(n - 1, depth + 1);
//   };
//   const recur2 = (n, depth) => {
//     if (depth === K) {
//       return;
//     }
//     child = child * n;
//     recur2(n + 1, depth + 1);
//   };
//   recur1(N - 1, 1);
//   recur2(1, 0);
//   console.log(Math.floor(parent / child));
// };

// solution(input);
const solution = (input) => {
  const [N, K] = input[0].split(" ").map(Number);
  let answer = 0;
  const comb = (start, cnt) => {
    if (cnt === K) {
      answer++;
      return;
    }
    for (let i = start; i <= N; i++) {
      comb(i + 1, cnt + 1);
    }
  };
  comb(1, 0);
  console.log(answer);
};

solution(input);
