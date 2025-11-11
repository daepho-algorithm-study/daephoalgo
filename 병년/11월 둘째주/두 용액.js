const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);
  const arr = input[1].split(" ").map(Number);

  arr.sort((a, b) => a - b);

  const tp = () => {
    let mn = Infinity;
    let result = Array(2).fill(0);
    // 투포인터 용 시작과 끝 값
    let start = 0;
    let end = N - 1;
    while (start < end) {
      // 두 용액의 합
      let sm = arr[start] + arr[end];
      // 합 최소값 구하기
      if (mn > Math.abs(sm)) {
        mn = Math.abs(sm);
        // 배열에 할당
        result[0] = arr[start];
        result[1] = arr[end];
      }
      // 최소 값이 0 보다 작으면 start 를 올려서 최소 값을 찾을 수 있는 지 판별
      if (sm < 0) {
        start++;
      } else {
        // 아니라면 낮춰서 판별
        end--;
      }
    }
    return result;
  };
  let result = tp();
  // 내림차순 정렬
  result.sort((b, a) => b - a);
  console.log(result[0], result[1]);
};
solution(input);
