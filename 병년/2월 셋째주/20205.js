const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, K] = input[idx++].split(" ").map(Number);
  let result = [];

  for (let i = 0; i < N; i++) {
    const str = input[idx++];

    const expended = str
      .split("")
      .map((ch) => ch.repeat(K))
      .join("")
      .replaceAll(" ", "");

    for (let j = 0; j < K; j++) {
      result.push(expended);
    }
  }

  for (let i = 0; i < result.length; i++) {
    console.log(result[i].replaceAll("", " ").trim());
  }
};

solution(input);
