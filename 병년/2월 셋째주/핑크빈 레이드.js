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
  let yoon = input[0].split(" ").map(Number);
  let dal = input[1].split(" ").map(Number);
  let fo = input[2].split(" ").map(Number);

  let pink = Number(input[3]);
  pink = pink - yoon[1] - dal[1] - fo[1];
  let time = 0;
  while (pink > 0) {
    time++;
    if (time % yoon[0] === 0) {
      pink -= yoon[1];
    }
    if (time % dal[0] === 0) {
      pink -= dal[1];
    }
    if (time % fo[0] === 0) {
      pink -= fo[1];
    }
  }

  console.log(time);
};
solution(input);
