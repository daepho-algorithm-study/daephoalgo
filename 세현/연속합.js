const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, nums) {
  // 초기값 설정
  let mxVal = -1001;  // 최댓값
  let cur = 0;        // 현재까지의 누적값

  for (let i = 0; i < N; i++) { 

    // 핵심 줄
    cur = Math.max(nums[i], cur + nums[i]);
    // 현재 요소가 이전까지의 누적값에다 현재 요소를 더한 값보다 크면 그 누적값을 버림
    // 이전까지의 누적값은 음수라는 의미이므로 아예 더하지 않는 게 더 나은 결과를 가져옴
    // 카데인 알고리즘


    // 누적값과 현재 최댓값 비교하면서 갱신 
    mxVal = Math.max(mxVal, cur);
  }

  // 원래는 모든 시작점과 끝점을 다 조합해서 기록하려고 했었음(투포인터 느낌으로)
  // 그럼 시간복잡도와 공간 복잡도가 터짐 (둘 다 N^2)

  return mxVal;
}

console.log(solution(input[0][0], input[1]));
