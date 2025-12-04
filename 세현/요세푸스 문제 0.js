const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0][0],
    K = input[0][1];
  const answer = new Array();
  const q_list = Array.from({ length: N + 1 }, (v) => true);
  q_list[0] = false;
  let current_point = 0;
  for (let i = 0; i < N; i++) {
    let cnt = 0;
    while (cnt < K) {
      current_point = (current_point + 1) % (N + 1);
      if (q_list[current_point]) {
        cnt++;
      }
      // console.log(`현재 cur: ${current_point} // 현재 cnt:${cnt} // K번째인가?: ${cnt === K}`)
    }
    q_list[current_point] = false;
    answer.push(current_point);
  }

  return answer.join(", ");
}

console.log(`<${solution(input)}>`);
