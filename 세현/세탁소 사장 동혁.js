const fs = require("fs");

const input = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split("\n").map(e => Number(e));

function solution(input) {
  let answer = '';
  const money = input.slice(1);
  // 돈의 단위
  const unit = [25, 10, 5, 1]

  //큰 단위부터 나눠주고 나머지를 그 다음 단위로 나누길 반복해주면 됨
  money.forEach((coin) => {
    for (let i = 0; i < 4; i++) {
        const coins = Math.floor(coin / unit[i]);
        coin = coin % unit[i];
        answer += coins.toString() + ' ';
    }
  answer = answer.trim() + '\n';
  })

  return answer.trim()
}

console.log(solution(input));
