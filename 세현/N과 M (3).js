const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M) {
  const visited = Array.from({ length: N + 1 }, () => 0);
  const arr = Array.from({ length: N }, (v, i) => i + 1);
  const answer = [];

// 중복 순열
  const perm = (m, depth, result) => {

    if (depth === m) {
      answer.push(result.join(" "));
      return;
    }
    // 일반 순열에서 visited를 생략하면 됨
    for (const a of arr) {
      result.push(a);

      perm(m, depth + 1, result);

      result.pop();
    }
  };
  perm(M, 0, []);
  return answer.join("\n");
}

console.log(solution(input[0][0], input[0][1]));
