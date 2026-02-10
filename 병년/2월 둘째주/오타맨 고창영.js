const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);

  for (let i = 1; i <= N; i++) {
    const [idx, str] = input[i].split(" ");

    const arr = str.split("");
    const newArr = arr.filter((_, index) => {
      return index !== Number(idx) - 1;
    });
    console.log(newArr.join(""));
  }
};
solution(input);
