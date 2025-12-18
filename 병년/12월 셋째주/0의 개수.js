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
  const T = input[0];
  for (let tc = 1; tc <= T; tc++) {
    const [N, M] = input[tc].split(" ").map(Number);
    let cnt = 0;
    for (let i = N; i <= M; i++) {
      let str = i.toString();

      for (let char of str) {
        if (char === "0") cnt++;
      }
    }
    console.log(cnt);
  }
};
solution(input);
