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
  let T = input[idx++];

  for (let tc = 0; tc < T; tc++) {
    let str = input[idx++];

    let size = str.length;

    const recur = (left, right, depth) => {
      if (left >= right) {
        console.log(1 + " " + depth);
        return;
      }

      if (str[left] === str[right]) {
        recur(left + 1, right - 1, depth + 1);
      } else {
        console.log(0 + " " + depth);
        return;
      }
    };

    recur(0, size - 1, 1);
  }
};
solution(input);
