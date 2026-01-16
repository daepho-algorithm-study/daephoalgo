const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let [N, K] = input.shift().split(" ").map(Number);
  // 동전 내림차순으로 정렬
  const coins = input.map(Number).sort((a, b) => b - a);
  let cnt = 0;
  for (let coin of coins) {
    // 카운트에 금액이 높은 순서부터 몫을 구한 후 누적
    cnt += Math.floor(K / coin);
    // K 는 동전의 몫을 구한 나머지로 바꿔주기
    K = K % coin;
  }

  console.log(cnt)
};
solution(input);
