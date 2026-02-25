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
  const str = input[1];
  let newStr = "";

  for (let i = 0; i < str.length; i += N) {
    newStr += str[i];
  }

  console.log(newStr);
};
solution(input);
