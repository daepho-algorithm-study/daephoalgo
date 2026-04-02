const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const _class = [];
  const result = [];
  const arr = Array.from({ length: N }, () => Array(N).fill(0));
  for (let i = 0; i < N; i++) {
    _class.push(input[idx++].split(" ").map(Number));
  }

  for (let i = 0; i < 5; i++) {
    for (let j = 0; j < N; j++) {
      for (let k = j + 1; k < N; k++) {
        if (_class[j][i] === _class[k][i]) {
          arr[j][k] = 1;
          arr[k][j] = 1;
        }
      }
    }
  }
  for (let i = 0; i < arr.length; i++) {
    let cnt = 0;
    for (let j = 0; j < arr[0].length; j++) {
      if (arr[i][j]) cnt++;
    }
    result[i] = cnt;
  }
  let mx = Math.max(...result);

  answer = 0;
  for (let i = 0; i < result.length; i++) {
    if (mx === result[i]) {
      answer = i + 1;
      break
    }
  }
  console.log(answer);
};
solution(input);
