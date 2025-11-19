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
  const [M, N] = input[0].split(" ").map(Number);

  const arr = input[1].split(" ").map(Number);

  arr.sort((a, b) => a - b);
  const bis = () => {
    let left = 1;
    let right = arr[arr.length - 1];
    let answer = 0;

    while (left <= right) {
      let mid = Math.floor((left + right) / 2);

      let cnt = 0;
      // 과자를 현재 설정한 길이로 나눴을 때 몇개가 나오는 지 계산
      for (let snack of arr) {
        cnt += Math.floor(snack / mid);
      }
      // 만약 나눈 개수가 M보다 크거나 같을 경우 정답 갱신 후 값을 늘려서 더 탐색하기
      if (cnt >= M) {
        left = mid + 1;
        answer = mid;
        // 아니라면 범위 줄이기
      } else {
        right = mid - 1;
      }
    }
    return answer;
  };
  let result = bis();
  console.log(result);
};
solution(input);
