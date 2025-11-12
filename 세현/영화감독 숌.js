const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {

  // 첫 번째는 666이므로 초기값(0번째)를 665로 세팅
  let answer = 665;
  // cnt를 증가시키면서 N 번째 영화제목을 찾음
  let cnt = 0;
  const N = input[0];

  // N 번째 영화제목을 찾기 위해 N까지 카운팅함
  while (cnt < N) {
    answer += 1;
    if (String(answer).includes('666')) {
      // 만약 제목에 666이 포함되어 있으면 카운트하기
        cnt += 1
    }
  }

  return answer;
}

console.log(solution(input));
