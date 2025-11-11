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
  const arr1 = input[1].split(" ").map(Number);
  arr1.sort((a, b) => a - b);
  const M = Number(input[2]);
  const arr2 = input[3].split(" ").map(Number);
  const result = Array(arr2.length).fill(0);

  const bis = () => {
    // 가지고 있지 않은 숫자 카드의 원소 만큼 이분탐색 수행
    for (let i = 0; i < M; i++) {
      // left 값 설정
      let left = 0;
      // right 값 설정
      let right = N - 1;
      if (arr2[i] < arr1[left] || arr2[i] > arr1[right]) continue;
      while (left <= right) {
        // 현재 값
        let mid = Math.floor((left + right) / 2);

        // 만약 arr2[i]의 원소가 arr1[mid] 즉 해당 카드가 상근이가 가지고 있는 카드 중 하나라면
        if (arr2[i] === arr1[mid]) {
          // 값 갱신 후 while 문 탈출 후 다음 원소 보러가기
          result[i] = 1;
          break;
        } else if (arr2[i] > arr1[mid]) left = mid + 1;
        else right = mid - 1;
      }
    }
  };
  bis();
  console.log(result.join(" "));
};

solution(input);
