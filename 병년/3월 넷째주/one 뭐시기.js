const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const T = Number(input[idx++]);
  for (let tc = 0; tc < T; tc++) {
    const N = Number(input[idx++]);
    const peoples = input[idx++].split(" ").map(Number);
    const count = {};
    let answer = 0;
    peoples.forEach((item) => {
      count[item] = (count[item] || 0) + 1;
    });
    for (let i = 0; i < peoples.length; i++) {
      if (count[peoples[i]] === 1) {
        answer = peoples[i];
      }
    }
    console.log(`Case #${tc + 1}: ${answer}`);
  }
};
solution(input);
