const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  let arr = input.slice(1).map((line) => line.split(" ").map(Number));
  let blue = 0;
  let white = 0;

  const recur = (r, c, cnt) => {
    if (cnt === 1) {
      if (arr[r][c] === 1) {
        blue++;
      } else {
        white++;
      }
      return;
    }

    let color = arr[r][c];

    for (let i = r; i < r + cnt; i++) {
      for (let j = c; j < c + cnt; j++) {
        if (color !== arr[i][j]) {
          let half = cnt / 2;
          recur(r, c, half);
          recur(r, c + half, half);
          recur(r + half, c, half);
          recur(r + half, c + half, half);

          return;
        }
      }
    }
    if (color === 1) {
      blue++;
    } else {
      white++;
    }
  };
  recur(0, 0, N);
  console.log(white, blue);
};
solution(input);
