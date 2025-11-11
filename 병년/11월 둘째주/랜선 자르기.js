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
  const [N, M] = input[0].split(" ").map(Number);
  const arr = input
    .slice(1, N + 1)
    .map(Number)
    .sort((a, b) => a - b);

  const bis = () => {
    let left = 1;
    let right = arr[N - 1];
    let answer = 0;

    while (left <= right) {
      let cnt = 0;
      let mid = Math.floor((left + right) / 2);
      for (let num of arr) {
        cnt += Math.floor(num / mid);
      }
      if (cnt >= M) {
        answer = mid;
        left = mid + 1;
      } else right = mid - 1;
    }
    return answer;
  };
  console.log(bis());
};

solution(input);
