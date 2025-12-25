const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const answer = [];

  const cantor = (str) => {
    const ln = str.length;
    if (ln === 1) {
        return str;
    }

    const fst = str.slice(0, ln/3);
    const sec = str.slice(ln/3, (ln/3 * 2));
    const trd = str.slice((ln/3 * 2), ln);

    return cantor(fst) + cantor(sec).replaceAll('-', ' ') + cantor(trd);
  }

  for (const N of input) {
    const cube = 3**N;
    const initstr = "-".repeat(cube);
    answer.push(cantor(initstr));
  }

  return answer.join('\n');
}

console.log(solution(input));


/* 최적화된 풀이 (메모리 1/3, 속도 1/4)
function solution(input) {
  const getCantor = (n) => {
    // 기저 조건: n이 0이면 문자 하나('-') 반환
    if (n === 0) return "-";

    const prevCantor = getCantor(n - 1); // 이전 단계 (n-1)의 결과
    const spaces = " ".repeat(Math.pow(3, n - 1)); // 가운데 들어갈 공백

    // n 단계 = (n-1단계) + (n-1단계 길이만큼의 공백) + (n-1단계)
    return prevCantor + spaces + prevCantor;
  };

  return input.map(n => getCantor(n)).join('\n');
}
*/