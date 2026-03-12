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
  const N = Number(input[0]);
  const freq = Array(1000001).fill(0);
  const arr = input[1].split(" ").map(Number);
  const result = Array.from({ length: N }, () => -1);
  const stack = [];
  for (let i = 0; i < N; i++) {
    freq[arr[i]]++;
  }

  for (let i = 0; i < N; i++) {
    while (stack.length && freq[arr[stack[stack.length - 1]]] < freq[arr[i]]) {
      const top = stack.pop();
      result[top] = arr[i];
    }
    stack.push(i);
  }
  console.log(result.join(" "));
};
solution(input);
