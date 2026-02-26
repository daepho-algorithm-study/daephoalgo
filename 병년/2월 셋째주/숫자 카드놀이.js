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
  while (true) {
    let num = input[idx++];
    if (num === "0") return;
    if (num.length === 1) {
      console.log(num);
      continue;
    }
    const result = [];
    const recur = (n) => {
      let arr = n.split("").map(Number);
      if (arr.length === 1) {
        result.push(n);
        return;
      }
      let next = 1;
      for (let i = 0; i < arr.length; i++) {
        next *= arr[i];
      }
      result.push(n);
      recur(next.toString());
    };

    recur(num);
    console.log(result.join(" "));
  }
};
solution(input);
