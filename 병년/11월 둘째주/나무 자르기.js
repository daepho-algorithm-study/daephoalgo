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

  const arr = input[1].split(" ").map(Number);

  arr.sort((a, b) => a - b);

  const bis = () => {
    // 절단기 높이의 최소 값
    let left = 0;
    // 절단기 높이의 최대 값
    let right = arr[arr.length - 1];
    let answer = 0;
    // 이분 탐색
    while (left <= right) {
      let cnt = 0;
      // 중간값 설정
      let mid = Math.floor((right + left) / 2);
      // cnt 누적을 위한 반복문
      for (let num of arr) {
        if (mid < num) {
          cnt += num - mid;
        }
      }
      // cnt의 값이 M 보다 크다면 ==> 나무가 많이 잘렸다면 절단기의 높이를 높여야 함
      if (cnt >= M) {
        // 정답 후보기 때문에 할당
        answer = mid;
        // 혹시 한칸을 더 늘려도 cnt 의 값이 M 보다 더 클 수 있기 때문에 높이 높여주기
        left = mid + 1;
      } else {
        // 아닌 경우에는 무조건 절단기의 길이를 줄여야 함
        right = mid - 1;
      }
    }
    return answer;
  };
  let answer = bis();
  console.log(answer);
};
solution(input);
