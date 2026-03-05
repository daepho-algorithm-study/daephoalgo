const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [p, w] = input[0].split(" ").map(Number);
  const str = input[1];
  const keboard = [[], ["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"], ["J", "K", "L"], ["M", "N", "O"], ["P", "Q", "R", "S"], ["T", "U", "V"], ["W", "X", "Y", "Z"]];

  let total = 0;
  let past = 0;
  for (let i = 0; i < str.length; i++) {
    if (str[i] === " ") {
      total += p;
      past = 0;
    }
    for (let j = 0; j < keboard.length; j++) {
      for (let k = 0; k < keboard[j].length; k++) {
        if (str[i] === keboard[j][k]) {
          if (j === past) {
            total += w;
          }
          total += (1 + k) * p;
          past = j;
        }
      }
    }
  }
  console.log(total);
};
solution(input);
