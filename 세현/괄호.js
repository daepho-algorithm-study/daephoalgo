const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const T = Number(input[0]);
  const answer = new Array;
  for(let i = 1; i <= T; i++) {
    const stack = new Array;
    const PS = input[i].replace('\r', '').split("");
    let isComplete = true;
    for (let j = 0; j < PS.length; j++) {
        if (PS[j] === '(') {
            stack.push(PS[j]);
        } else {
            if (stack.length) {
                stack.pop();
            } else {
                answer.push("NO");
                isComplete = false;
                break;
            }
        }
    }
    if (isComplete) {
        if (stack.length) {
            answer.push("NO");
        } else {
            answer.push("YES")
        }
    } else {
        continue;
    }
  }

  return answer.join('\n');
}

console.log(solution(input));
