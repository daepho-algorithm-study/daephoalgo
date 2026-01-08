const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [size, K] = input[0].split(" ").map(Number);
  const arr = input[1].split(" ").map(Number);
  let cnt = 0;
  let temp = Array(size);
  let answer;

  const merge_sort = (p, r) => {
    if (p >= r) return;
    if (p < r) {
      let q = Math.floor((p + r) / 2);
      merge_sort(p, q);
      merge_sort(q + 1, r);
      merge(p, q, r);
    }
  };

  const merge = (p, q, r) => {
    let i = p,
      j = q + 1,
      t = 0;
    while (i <= q && j <= r) {
      if (arr[i] <= arr[j]) temp[t++] = arr[i++];
      else temp[t++] = arr[j++];
    }
    while (i <= q) temp[t++] = arr[i++];
    while (j <= r) temp[t++] = arr[j++];

    i = p;
    t = 0;
    while (i <= r) {
      arr[i++] = temp[t++];
      cnt++;
      if (cnt === K) answer = arr[i - 1];
    }
  };

  merge_sort(0, size - 1);
  if (answer === undefined) answer = -1;
  console.log(answer);
};
solution(input);
