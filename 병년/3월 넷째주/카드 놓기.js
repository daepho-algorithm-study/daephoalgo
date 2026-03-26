const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const K = Number(input[idx++]);
  const set = new Set();
  const arr = [];
  const visited = Array.from({ length: N }, () => false);
  for (let i = 0; i < N; i++) {
    const num = input[idx++];
    arr.push(num);
  }
  const dfs = (depth, num) => {
    if (depth === K) {
      set.add(Number(num));
      return;
    }
    for (let i = 0; i < N; i++) {
      if (!visited[i]) {
        visited[i] = true;
        dfs(depth + 1, num + arr[i]);
        visited[i] = false;
      }
    }
  };
  dfs(0, "");
  console.log(set.size);
};
solution(input);
