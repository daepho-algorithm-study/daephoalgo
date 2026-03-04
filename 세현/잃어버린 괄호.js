const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(str) {
  let answer = 0;
  let flag = 0;
  let sign = 1;

  for (let i = 0; i < str.length; i++) {
    if (str[i] === '+' || str[i] === '-' || i === str.length-1) {
      
      if (i === str.length-1) i += 1;

      const cur_num = Number(str.slice(flag, i));

      flag = i+1;

      answer += cur_num * sign

      if (str[i] === '-') sign = -1;
    }
  }

  return answer;
}

console.log(solution(input[0]));
