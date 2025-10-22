const fs = require("fs");

// const input = fs.readFileSync("input.txt").toString().trim().split(" ");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");

function solution(inp) {
  // 10진법을 N진법으로 나누는 방법 -> 수를 진수만큼 나누고 나머지를 작은 자리서부터 채우기를 반복
  const [n, b] = inp;
  let num = Number(n);
  let base = Number(b);
  let namuji = 0;
  let answer = '';
  while (num >= base) {
    namuji = num % base;
    num = Math.floor(num / base);
    // String.fromCharCode --->> 문자를 ASCII로 변환하는 js 라이브러리
    answer = answer + String.fromCharCode(namuji+(namuji < 10 ? 48 : 55));
  }
  answer = answer + String.fromCharCode(num+(num < 10 ? 48 : 55));
  // answer는 맨 앞에서부터 작은자리수를 채워넣었으므로 반대로 뒤집어줘야 함
  return answer.split('').reverse().join('');
}

console.log(solution(input));
