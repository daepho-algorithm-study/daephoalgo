const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  // .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const M = input[0][1], N = input[0][0];
  const cards = input[1];

  let answer = 0;
  // N개의 카드 중에서 3개를 고르므로(nC3) 3중 포문
  for (let i = 0; i < N-2; i++) {
    for (let j = i+1; j < N-1; j++) {
      for (let k = j+1; k < N; k++) {
        //카드 3개를 모두 더해서 M보다 작은 최대의 수를 갱신
        const blackjack = cards[i] + cards[j] + cards[k];
        if (blackjack <= M && blackjack > answer) {
          answer = blackjack;
        }
      }
    }
  }


  return answer;
}

console.log(solution(input));
