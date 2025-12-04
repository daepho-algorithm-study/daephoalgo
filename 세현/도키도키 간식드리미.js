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
  const N = input[0][0];
  const line = input[1].reverse();
  let cur_number = 1;
  const stack = new Array;
  while(cur_number <= N) {
    if (line.length) {
        const line_front = line[line.length-1];
        if (line_front === cur_number) {
            line.pop();
            cur_number++;
        } else {
            if (stack.length) {
                const stack_front = stack[stack.length-1];
                if (stack_front === cur_number) {
                    stack.pop();
                    cur_number++;
                } else {
                    stack.push(line.pop());
                }
            } else {
                stack.push(line.pop());
            }
        }
    } else {
        if (stack.length) {
            const stack_front = stack.pop();
            if (stack_front === cur_number) {
                cur_number++;
            } else {
                return "Sad";
            }
        } else return "Sad";
    }
  }

  return "Nice";
}

console.log(solution(input));
