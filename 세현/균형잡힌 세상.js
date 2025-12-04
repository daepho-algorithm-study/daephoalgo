const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");
//   .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const answer = new Array();
  for (let i = 0; i < input.length - 1; i++) {
    const stack = new Array();
    let isComplete = true;
    for (const ch of input[i].split("")) {
      if (ch === "(" || ch === "[") {
        stack.push(ch);
      } else if (ch === ")") {
        if (stack.length) {
          if (stack[stack.length - 1] === "(") {
            stack.pop();
          } else {
            answer.push("no");
            isComplete = false;
            break;
          }
        } else {
          answer.push("no");
          isComplete = false;
          break;
        }
      } else if (ch === "]") {
        if (stack.length) {
          if (stack[stack.length - 1] === "[") {
            stack.pop();
          } else {
            answer.push("no");
            isComplete = false;
            break;
          }
        } else {
          answer.push("no");
          isComplete = false;
          break;
        }
      }
    }
    if (isComplete) {
      if (stack.length === 0) answer.push("yes");
       else answer.push("no");
    } 
  }

  return answer.join('\n');
}

console.log(solution(input));
