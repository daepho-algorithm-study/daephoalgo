const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  const inp = input.slice(0, -1);
  const answer = [];
  inp.forEach((n) => {
    let ans = `${n} = `;
    let measures = [];
    //제곱근 방식으로 약수 판별
    for (let i = 1; i * i <= n; i++) {
      if (n % i === 0) {
        measures.push(i);
        if (i !== n / i) measures.push(n / i); // i가 약수이면 n/i 도 약수가 됨(대칭)
      }
    }
    measures = measures.sort((a, b) => a - b).slice(0, -1);
    if (measures.reduce((a, b) => a + b, 0) === n) {
      measures.forEach((e) => {
        ans += `${e} + `;
      });
      ans = ans.slice(0, -3) + "\n";
    } else {
      ans = `${n} is NOT perfect.\n`;
    }
    answer.push(ans);
  });

  return answer.join("").trim();
}

console.log(solution(input));
