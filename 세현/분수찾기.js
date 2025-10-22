const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  // 수학을 가장한 패턴 찾기 문제
  // 분자와 분모를 완전히 분리해서 패턴을 파악해야 함

  const N = input[0];
  if (N === 1) {
    return '1/1';
  }

  
  // 분자 파트에선 1 1 2 3 2 1 1 2 3 4 5 4 3 2 1 1 2 3 4 5 6 7 6 5 4 3 2 1 ... 이런 순서가 됨
  // 패턴으로 묶으면 1 [1 2 3 2 1] [1 2 3 4 5 4 3 2 1] [1 2 3 4 5 6 7 6 5 4 3 2 1]
  // 맨 처음 1을 제외하고 그 다음부터 최초 3에서 시작하여 2씩 늘어난 대칭 수열을 찾을 수 있음
  // 마찬가지로 분모 파트에선 1 2 1 1 2 3 4 3 2 1 1 2 3 4 5 6 5 4 3 2 1 ... 이런 순서가 됨
  // 패턴으로 묶으면 [1 2 1] [1 2 3 4 3 2 1] [1 2 3 4 5 6 5 4 3 2 1]
  // 분모는 처음부터 대칭 수열을 찾을 수 있음. 최초 2부터 2씩 늘어난 대칭수열임.

  // fir이 분자고 sec이 분모에 해당함
  // 분자는 맨 처음 1을 제외해야 함 (예외로 1을 처리해줘서 제외 가능)
  let fir = N-1;
  let fircnt = 3
  let sec = N;
  let seccnt = 2;
  
  // 각 기준의 대칭수열 개수 만큼 분자, 분모를 빼주다 보면 최종 순서의 분자를 찾을 수 있음
  while (fir > (fircnt*2-1)) {
    fir -= (fircnt*2-1);
    fircnt += 2;
  }
  if (fir > fircnt) {
    const firarr = [...Array(fircnt).keys()].slice(1).reverse()
    fir = firarr[fir-fircnt-1];
  }
  while (sec > (seccnt*2-1)) {
    sec -= (seccnt*2-1);
    seccnt += 2;
  }
  if (sec > seccnt) {
    const secarr = [...Array(seccnt).keys()].slice(1).reverse()
    sec = secarr[sec-seccnt-1];
  }
  return fir + '/' + sec;
}

console.log(solution(input));
