const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0];
  const nums = input.slice(1).sort((a, b) => a - b);

  // 최빈값 구하기
  const num_cnt = new Map();
  for (const num of nums) {
    num_cnt.set(num, (num_cnt.get(num) || 0) + 1);
  }
  let mxfreq = 0,
    modes = [];
  for (const num of num_cnt.keys()) {
    const curfreq = num_cnt.get(num);
    if (curfreq > mxfreq) {
      mxfreq = curfreq;
      modes = [num];
    } else if (curfreq === mxfreq) {
      modes.push(num);
    }
  }
  const mode = modes.length > 1 ? modes[1] : modes[0];

  const answer = [];
  answer.push(Math.round(nums.reduce((p, c) => p + c) / N)); // 산술평균
  answer.push(nums[(N - 1) / 2]); // 중앙값
  answer.push(mode); // 최빈값
  answer.push(nums[N - 1] - nums[0]); // 범위

  return answer.join("\n");
}

console.log(solution(input));
