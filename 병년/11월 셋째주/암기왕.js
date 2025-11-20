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
    const N = Number(input[idx++]);
    const arr1 = input[idx++].split(" ").map(Number);
    arr1.sort((a, b) => a - b);
    const M = Number(input[idx++]);
    const arr2 = input[idx++].split(" ").map(Number);
    const result = Array(arr2.length).fill(0);

    const bis = () => {
      for (let i = 0; i < M; i++) {
        let left = 0;
        let right = N - 1;

        while (left <= right) {
          let mid = Math.floor((left + right) / 2);
          // arr2 즉 수첩2 수첩1 의 값이 존재하면
          if (arr2[i] === arr1[mid]) {
            // result 배열 재할당 후 종료
            result[i] = 1;
            break;
          }
          // 이분 탐색으로 범위 설정
          else if (arr2[i] > arr1[mid]) left = mid + 1;
          else right = mid - 1;
        }
      }
    };
    bis();
    console.log(result.join("\n"));
  }
};
solution(input);
