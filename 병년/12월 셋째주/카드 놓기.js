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

const solution = (input) => {
  let idx = 0;
  const arr = [];
  const N = Number(input[idx++]);
  const K = Number(input[idx++]);
  for (let i = 0; i < N; i++) {
    arr.push(Number(input[idx++]));
  }

  const set = new Set();
  const visited = Array.from({ length: N }, () => false);

  const dfs = (depth, num) => {
    if (depth === K) {
      set.add(Number(num));
      return;
    }
    for (let i = 0; i < N; i++) {
      if (visited[i] === false) {
        visited[i] = true;
        dfs(depth + 1, num.toString() + arr[i].toString());
        visited[i] = false;
      }
    }
  };
  dfs(0, "");
  console.log(set.size);
};
solution(input);
