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
  const N = input[0];
  const stack = new Array, answer = new Array;
  for (let i = 1; i <= N; i++) {
    switch (true) {
        case input[i][0] === 1:
            stack.push(input[i][1]);
            break;
        case input[i][0] === 2:
            if (stack.length) {
                answer.push(stack.pop());
            } else {
                answer.push(-1);
            }
            break;
        case input[i][0] === 3:
            answer.push(stack.length);
            break;
        case input[i][0] === 4:
            if (stack.length) {
                answer.push(0);
            } else {
                answer.push(1);
            }
            break;
        case input[i][0] === 5:
            if (stack.length) {
                answer.push(stack[stack.length-1]);
            } else {
                answer.push(-1);
            }
            break;
    }
  }

  return answer.join('\n');
}

console.log(solution(input));
