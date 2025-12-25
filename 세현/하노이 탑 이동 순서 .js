const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N) {
  let K = 0;
  const answer = [];
  const hanoi = (n, source, target, auxiliary) => {
    if (n === 0) return;

    // n번 원판 위에 쌓여있는 n-1개를 보조(auxiliary)로 치워야 함
    hanoi(n - 1, source, auxiliary, target);

    // n번 원판을 목적지(target)로 옮김
    // 실제로 조작된 원판이므로 실행 횟수 증가
    answer.push(`${source} ${target}`);
    K++;

    // 보조의 n-1개를 목적지 위에 쌓음
    // 이제 비어있는 source가 auxiliary로 바뀜
    hanoi(n - 1, auxiliary, target, source);
  };
  hanoi(N, 1, 3, 2);
  return `${K}\n` + answer.join("\n");
}

console.log(solution(input[0]));
