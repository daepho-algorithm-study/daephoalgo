const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, arr) {
  let answer = "+\n";
  const stack = [1];
  let index = 0;
  let num = 2;
  while(index < N) {

    if (stack[stack.length-1] === arr[index]) {
      answer += '-\n';
      stack.pop();
      index++;
      continue;
    }

    stack.push(num);
    answer += '+\n';
    num++;

    if (num > N+1) {
      answer = "NO";
      break;
    }
  }


  return answer.trim();
}
const N = Number(input[0]);
const arr = input.slice(1).map(Number);
console.log(solution(N, arr));
