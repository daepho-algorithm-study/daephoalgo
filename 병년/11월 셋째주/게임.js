const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [X, Y] = input[0].split(" ").map(Number);

  const bis = () => {
    let z = (100 * Y) / X;

    if (z >= 99) return -1;
    let left = 0;
    let right = X;
    let result = 0;

    while (left <= right) {
      let mid = Math.floor((right + left) / 2);
      let temp = Math.floor((100 * (Y + mid)) / (X + mid));
      if (temp > z) {
        result = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return result;
  };

  let result = bis();
  console.log(result);
};
solution(input);
