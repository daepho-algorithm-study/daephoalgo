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
  const bis = (num) => {
    const arr = [];
    let left = 1;
    let right = 50;

    while (left <= right) {
      let mid = Math.floor((left + right) / 2);
      arr.push(mid);
      if (mid < num) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
      if (mid === num) {
        break;
      }
    }
    return arr;
  };
  let idx = 0;
  while (true) {
    let num = Number(input[idx++]);
    if (num === 0) break;

    const result = bis(num);
    console.log(result.join(" "));
  }
};

solution(input);
