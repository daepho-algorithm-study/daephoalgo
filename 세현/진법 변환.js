const fs = require("fs");

// const input = fs.readFileSync("input.txt").toString().trim().split(" ");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");

function solution(inp) {
  // N진수를 10진법으로 바꾸는 방법 -> 맨 뒷자리수부터 자릿수 와 진수의 거듭제곱을 곱하여 누적시키면 됨
  const [n, b] = inp;
  const nzin = [...n];
  let i = 1;
  let answer = 0;
  //작은 자리수부터 해야하므로 원본을 반대로 뒤집어야 함
  nzin.reverse().forEach((num) => {
    answer = answer + (num.charCodeAt() - (num.charCodeAt() > 64 ? 55 : 48)) * i;

    i *= b;
  })
  return answer;
}

console.log(solution(input));
