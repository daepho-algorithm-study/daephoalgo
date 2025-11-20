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
    const [N, M] = input[idx++].split(" ").map(Number);
    const arr1 = input[idx++].split(" ").map(Number);
    const arr2 = input[idx++].split(" ").map(Number);
    arr2.sort((a, b) => a - b);
    let count = 0;

    const bis = () => {
      let count = 0;
      // A 의 원소 탐색
      for (let num of arr1) {
        let left = 0;
        let right = arr2.length;
        // 이분탐색 시작
        while (left <= right) {
          let mid = Math.floor((left + right) / 2);
          // 만약 B[mid] 의 값이 A 의 원소보다 더 작다면 범위를 늘려서 탐색
          if (arr2[mid] < num) {
            left = mid + 1;
            // 아니라면 범위 줄이기
          } else right = mid - 1;
        }
        // left 의 값은 num 보다 작은 값들의 개수 이기 때문에 누적
        count += left;
      }
      return count;
    };
    count = bis();
    console.log(count);
  }
};
solution(input);
