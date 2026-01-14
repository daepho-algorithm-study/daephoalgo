const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, nums, symbols) {
  let min = 1e9,
    max = -1e9;
  const operators = [(a, b) => a + b, (a, b) => a - b, (a, b) => a * b, (a, b) => Math.trunc(a / b)];
  /* operators는 아래 스위치문과 같음(위는 배열에 람다식을 다 넣어놓은 것임)
    switch(i) {
        case 0:
            cal = nums[n-1]+nums[n];
            break;
        case 1:
            cal = nums[n-1]-nums[n];
            break;
        case 2:
            cal = nums[n-1]*nums[n];
            break;
        case 3:
            cal = Math.trunc(nums[n-1] / nums[n]);
            break;
    }
    */

  const dfs = (n, result) => {
    // 식이 완성되었으면 max min 갱신
    if (n === N) {
      if (result < min) {
        min = result;
      }

      if (result > max) {
        max = result;
      }
      return;
    }

    // 연산자 돌아가면서 비교해보기 ([0: +] [1: -] [2: *] [3: /])
    for (let i = 0; i < 4; i++) {
      // 현재 연산자가 남은게 없다면 패스
      if (symbols[i] === 0) continue;

      // 연산자가 있으면 하나 꺼내서 쓰기
      symbols[i]--;
      
      // 다음 루프에 그 다음 요소와 계산된 결과값 넘기기
      dfs(n + 1, operators[i](result, nums[n]));

      // 연산자 개수 복구해주기
      symbols[i]++;
    }
  };

  // result 초기값은 맨 첫번째 요소로 해놓으면 됨
  dfs(1, nums[0]);

  return [max, min].join("\n");
}

console.log(solution(input[0][0], input[1], input[2]));
