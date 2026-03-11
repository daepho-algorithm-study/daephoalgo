const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const result = [];
  let O = 0;
  let W = 0;
  let dead = false;
  const calc = (w, num) => {
    if (dead) {
      return "RIP";
    } else if (num > w * 0.5 && num < w * 2) {
      return ":-)";
    } else {
      return ":-(";
    }
  };
  while (true) {
    const [o, w] = input[idx++].trim().split(" ");

    if (o === "0" && w === "0") {
      break;
    } else if (o !== "F" && o !== "E" && o !== "#") {
      O = Number(o);
      W = Number(w);
      dead = false;
    } else if (o === "#" && w === "0") {
      const str = calc(O, W);
      result.push(str);
      O = 0;
      W = 0;
    } else {
      if (dead) continue;
      if (o === "F") {
        W += Number(w);
      } else if (o === "E") {
        W -= Number(w);
      }
      if (W <= 0) {
        dead = true;
      }
    }
  }

  for (let i = 0; i < result.length; i++) {
    console.log(`${i + 1} ${result[i]}`);
  }
};
solution(input);
