const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = input[idx++].split(" ").map(Number);
  const lis = [];

  const binary_search = (left, right, num) => {
    // mid 값 설정
    let mid = 0;
    // 왼쪽보다 오른쪽이 크면
    while (left < right) {
      // mid값 제 설정
      mid = Math.floor((left + right) / 2);
      // 만약 부분수열의 mid 번째 값이 num 보다 작다면
      // 왼쪽 값 늘리기
      if (lis[mid] < num) {
        left = mid + 1;
        // 아니라면 오른쪽 값 줄이기
      } else {
        right = mid;
      }
    }
    // left 값 반환
    return left;
  };

  lis.push(arr[0]);

  let index = 0;
  for (let i = 1; i < N; i++) {
    // 만약 다음 비교할 값이 더 크다면
    if (lis[lis.length - 1] < arr[i]) {
      // 부분수열 마지막에 현재 값 추가
      lis.push(arr[i]);
      // 아니라면
    } else {
      // 이진 탐색을 통해 붙일 수 있는 가장 최적의 자리 구하기
      index = binary_search(0, lis.length, arr[i]);
      lis[index] = arr[i];
    }
  }
  console.log(lis.length);
};
solution(input);
