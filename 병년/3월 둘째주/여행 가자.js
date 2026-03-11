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
  const N = Number(input[idx++]);
  const M = Number(input[idx++]);
  const arr = Array.from({ length: N }, (_, i) => i);
  const find = (x) => {
    if (arr[x] !== x) {
      arr[x] = find(arr[x]);
    }
    return arr[x];
  };
  const union = (a, b) => {
    let a1 = find(a);
    let b1 = find(b);

    if (a1 !== b1) {
      arr[b1] = a1;
    }
  };
  for (let i = 0; i < N; i++) {
    const info = input[idx++].split(" ").map(Number);
    for (let j = 1; j < info.length; j++) {
      if (info[j] === 1) union(i, j);
    }
  }

  let flag = true;
  const lastNum = input[idx++].split(" ").map(Number);
  let current = find(lastNum[0] - 1);
  for (let i = 1; i < lastNum.length; i++) {
    if (find(lastNum[i] - 1) === current) continue;
    else flag = false;
  }
  console.log(flag ? "YES" : "NO");
};

solution(input);
