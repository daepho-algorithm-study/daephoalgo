const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const korea = ["K", "O", "R", "E", "A"];
  let str = input[0];
  let total = 0;
  for (let i = 0; i < str.length; i++) {
    if (str[i] === korea[total % 5]) {
      total += 1;
    }
  }
  console.log(total);
};

solution(input);
