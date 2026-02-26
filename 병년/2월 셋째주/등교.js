const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [N, K] = input[0].split(" ").map(Number);
  let answer = -1;

  for (let i = 1; i <= N; i++) {
    const [X, T] = input[i].split(" ").map(Number);

    if (X + T <= K) {
      if (X > answer) {
        answer = X;
      }
    }
  }

  console.log(answer === 0 ? "-1" : answer);
};

solution(input);
