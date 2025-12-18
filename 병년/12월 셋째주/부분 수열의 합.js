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
  const [N, S] = input[idx++].split(" ").map(Number);

  let arr = input[idx++].split(" ").map(Number);
  let cnt = 0;
  const dfs = (depth, sum) => {
    if (depth === N) {
      if (sum === S) {
        cnt++;
      }
      return;
    }

    dfs(depth + 1, sum + arr[depth]);
    dfs(depth + 1, sum);
  };

  dfs(0, 0);

  if (S === 0) cnt += -1;

  console.log(cnt);
};
solution(input);
