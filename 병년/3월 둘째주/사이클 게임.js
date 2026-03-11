const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;

  const [N, M] = input[idx++].split(" ").map(Number);
  const parent = Array.from({ length: N + 1 }, (_, i) => i);
  const find = (x) => {
    if (parent[x] !== x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  };

  const union = (a, b) => {
    let a1 = find(a);
    let b1 = find(b);

    if (a1 !== b1) {
      parent[b1] = a1;
    }
  };
  for (let i = 1; i < M + 1; i++) {
    let [x, y] = input[idx++].split(" ").map(Number);
    let xi = find(x);
    let yi = find(y);

    if (xi === yi) {
      console.log(i);
      return;
    } else {
      union(xi, yi);
    }
  }
  console.log(0);
};
solution(input);
