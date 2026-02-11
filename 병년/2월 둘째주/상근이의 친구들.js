const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  while (true) {
    const [M, G] = input[idx++].split(" ").map(Number);
    if (M === 0 && G === 0) {
      break;
    }
    console.log(M + G);
  }
};

solution(input);
