const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" "));

// console.log(input);

function solution(str, q, questions) {
  let result = "";

  const N = str.length;

  // S[i][c]: 0~i-1 구간에서 c번째 알파벳 등장 횟수 누적합
  const S = Array.from({ length: N + 1 }, () => Array.from({ length: 26 }, () => 0));

  for (let i = 1; i <= N; i++) {
    const ascii = str[i - 1].charCodeAt() - 97;
    // 이전 누적합 복사
    S[i] = [...S[i - 1]];
    S[i][ascii] += 1;
  }

  // 각 쿼리 [문자, l, r] 구간 내 해당 문자 등장 횟수 계산
  for (const question of questions) {
    const chr = question[0].charCodeAt() - 97;
    const l = Number(question[1]),
      r = Number(question[2]);
    const answer = S[r + 1][chr] - S[l][chr];
    result += answer + "\n"
  }

  return result;
}

console.log(solution(input[0][0], Number(input[1][0]), input.slice(2)));