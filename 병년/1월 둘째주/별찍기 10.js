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
  const N = Number(input[0]);
  const arr = Array.from({ length: N }, () => Array(N).fill(" "));

  const recur = (i, j, n) => {
    if (n === 1) {
      arr[i][j] = "*";
      return;
    }

    const size = n / 3;

    for (let x = 0; x < 3; x++) {
      for (let y = 0; y < 3; y++) {
        if (x === 1 && y === 1) continue;

        recur(i + x * size, j + y * size, size);
      }
    }
  };

  recur(0, 0, N);

  console.log(arr.map((row) => row.join("")).join("\n"));
};

solution(input);
