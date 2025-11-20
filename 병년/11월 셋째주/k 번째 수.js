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
  const N = Number(input[0]);
  const K = Number(input[1]);

  const bis = () => {
    let left = 1;
    let right = N * N;
    let result = 0;
    while (left <= right) {
      let mid = Math.floor((left + right) / 2);

      let count = 0;

      for (let i = 1; i <= N; i++) {
        count += Math.min(Math.floor(mid / i), N);
      }

      if (count >= K) {
        result = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return result;
  };
  let result = 0;
  result = bis();
  console.log(result);
};

solution(input);
