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
  const dist = Array.from({ length: N }, () => Array(N).fill(Infinity));
  const score = Array(N).fill(0);
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (i === j) dist[i][j] = 0;
    }
  }

  while (true) {
    const [a, b] = input[idx++].split(" ").map(Number);
    if (a === -1 && b === -1) {
      break;
    }
    dist[a - 1][b - 1] = 1;
    dist[b - 1][a - 1] = 1;
  }

  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (let i = 0; i < dist.length; i++) {
    score[i] = Math.max(...dist[i]);
  }
  let min = 0;
  let cnt = 0;
  let answer = [];
  min = Math.min(...score);
  for (let i = 0; i < score.length; i++) {
    if (score[i] === min) {
      cnt++;
      answer.push(i + 1);
    }
  }
  console.log(min, cnt);
  console.log(answer.join(" "));
};
solution(input);
