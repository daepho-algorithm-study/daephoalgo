const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = input[idx++].split(" ").map(Number);
  const stack = [];
  const answer = Array(N).fill(-1);

  for (let i = 0; i < N; i++) {
    while (stack.length && arr[stack[stack.length - 1]] < arr[i]) {
      const top = stack.pop();
      answer[top] = arr[i];
    }
    stack.push(i);
  }

  console.log(answer.join(" "));
};
solution(input);
