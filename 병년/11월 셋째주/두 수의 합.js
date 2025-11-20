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
  let idx = 0;
  const T = Number(input[idx++]);
  for (let tc = 0; tc < T; tc++) {
    const [N, K] = input[idx++].split(" ").map(Number);
    const arr = input[idx++].split(" ").map(Number);
    arr.sort((a, b) => a - b);

    const tp = () => {
      let mn = Infinity;
      let start = 0;
      let end = N - 1;
      let cnt = 0;

      while (start < end) {
        let sm = arr[start] + arr[end];
        let diff = Math.abs(sm - K);

        if (diff < mn) {
          mn = diff;
          cnt = 1;
        } else if (mn === diff) {
          cnt++;
        }
        if (sm === K) {
          start++;
          end--;
        } else if (sm < K) {
          start++;
        } else if (sm > K) {
          end--;
        }
      }
      return cnt;
    };

    let cnt = tp();
    console.log(cnt);
  }
};
solution(input);
