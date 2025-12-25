const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));


// console.log(input);

const recursion = (str, left, right, cnt) => {
    if (left >= right) return `1 ${cnt}`;
    else if (str[left] != str[right]) return `0 ${cnt}`;
    else return recursion(str, left+1, right-1, cnt+1);
}

const isPalindrome = (str) => {
    return recursion(str, 0, str.length-1, 1);
}

function solution(input) {
  const T = Number(input[0]);
  const test_cases = input.slice(1);
  const answer = [];
  for (const test_case of test_cases) {
    answer.push(isPalindrome(test_case))
  }
  return answer.join('\n');
}

console.log(solution(input));
