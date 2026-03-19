const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [n, m] = input[idx++].split(" ").map(Number);
  const arr = Array.from({ length: n }, () => Array(n).fill(false));
  for (let i = 0; i < m; i++) {
    arr[i][i] = 0;
    const [a, b] = input[idx++].split(" ").map(Number);
    arr[a - 1][b - 1] = true;
  }

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (arr[i][k] && arr[k][j]) {
          arr[i][j] = true;
        }
      }
    }
  }
  let answer = 0;
  console.log(arr);
  for (let i = 0; i < n; i++) {
    let cnt = 0;
    for (let j = 0; j < n; j++) {
      if (arr[i][j] || arr[j][i]) {
        cnt++;
      }
    }
    if (cnt === n - 1) answer++;
  }
  console.log(answer);
};
solution(input);
