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
  const arr = input[1].split(" ").map(Number);
  const limit = Number(input[2]);
  let result = 0;
  const size = arr.length - 1;

  arr.sort((a, b) => a - b);
  // 만약 기본 배열의 전체 합이 limit 보다 작으면 최댓 값 출력
  if (arr.reduce((a, b) => a + b) <= limit) result = arr[size];

  const bis = () => {
    let left = 1;
    let right = arr[size];
    let answer = 0;

    // 이분 탐색 진행
    while (left <= right) {
      let sm = 0;
      let mid = Math.floor((right + left) / 2);

      for (let num of arr) {
        // 배열의 원소 값이 mid 보다 크다면
        if (num > mid) {
          // 누적합에 mid 추가
          sm += mid;
        } else {
          // 아니라면 num 추가
          sm += num;
        }
      }
      // 전체 합산이 limit 보다 작으면
      if (sm <= limit) {
        // 결과 값 재할당
        answer = mid;
        // 더 가능한 경우 탐색
        left = mid + 1;
      } else {
        // 아니라면 줄이기
        right = mid - 1;
      }
    }
    return answer;
  };

  result = bis();
  console.log(result);
};
solution(input);
