const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, distances, prices) {
  let total_price = 0n;
  prices[N-1] = 0;
  let minPrice = BigInt(prices[0]);
  
  for (let i = 0; i < N-1; i++) {
    if (BigInt(prices[i]) < minPrice) {
        minPrice = BigInt(prices[i]);
    }

    total_price += BigInt(distances[i]) * minPrice
  }

  return total_price.toString();
}

console.log(solution(input[0][0], input[1], input[2]));
