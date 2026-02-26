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

  const arr = input[idx++].split(" ").map(Number);

  const bubble_sort = (arr) => {
    let cnt = 0;
    for (let i = 0; i < N - 1; i++) {
      for (let j = 0; j < N - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];

          cnt++;

          if (cnt === K) return arr;
        }
      }
    }
    return null;
  };

  const result = bubble_sort(arr);
  console.log(result ? result.join(" ") : "-1");
};

solution(input);
