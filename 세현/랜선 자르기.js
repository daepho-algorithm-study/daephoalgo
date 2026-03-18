const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, K, lans) {
  let answer = 0;
  // left = 0으로 하면 터짐
  let [left, right] = [1, Math.max(...lans)]

  while (left <= right) {
    const middle = ~~((left + right) / 2)
    let total = 0
    for (let i = 0; i < K; i++) {
      total += ~~(lans[i] / middle);
    }

    if (total < N) {
      right = middle - 1;
    } else {
      answer = middle;
      left = middle + 1;
    }
  }

  return answer;
}

const [K, N] = input[0].split(" ").map(Number);
const lans = input.slice(1).map(Number);
console.log(solution(N, K, lans));
