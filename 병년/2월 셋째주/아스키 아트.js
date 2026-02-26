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
  const [N, M] = input[idx++].split(" ").map(Number);

  const calc = (r, g, b) => {
    return 2126 * r + 7152 * g + 722 * b;
  };

  const ascii = (num) => {
    if (num < 510000) {
      return "#";
    } else if (510000 <= num && num < 1020000) {
      return "o";
    } else if (1020000 <= num && num < 1530000) {
      return "+";
    } else if (1530000 <= num && num < 2040000) {
      return "-";
    } else if (2040000 <= num) {
      return ".";
    }
  };
  for (let i = 0; i < N; i++) {
    let str = input[idx++].split(" ").map(Number);
    let answer = "";

    for (let j = 0; j < str.length; j += 3) {
      let r = str[j];
      let g = str[j + 1];
      let b = str[j + 2];
      let num = calc(r, g, b);
      answer += ascii(num);
    }
    console.log(answer);
  }
};
solution(input);
