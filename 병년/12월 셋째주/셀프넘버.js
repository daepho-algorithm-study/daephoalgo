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
  const self_num = (num) => {
    let sum = 0;
    num = num.toString();
    for (let i = 0; i < num.length; i++) {
      sum += Number(num[i]);
    }

    result = Number(num) + sum;

    return result;
  };

  let arr = [];

  for (let i = 1; i < 10000; i++) {
    arr.push(self_num(i));
  }
  arr.sort((a, b) => a - b);
  for (let i = 1; i < arr.length + 1; i++) {
    if (!arr.includes(i)) console.log(i);
  }
};

solution(input);
