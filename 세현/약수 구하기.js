const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));

// console.log(input);
// 약수
function solution(input) {
  const [N, K] = input;
  let cnt = 0;
  let measure = 1;
  while (measure <= N) {  // 1부터 약수인지 확인
    if (N % measure === 0) {
        cnt++;            // 순서도 확인
        if (cnt === K) {  // K 번째 약수이면 리턴
            return measure;
        }
    }
    measure++;
  }
  return 0;
}

console.log(solution(input));
