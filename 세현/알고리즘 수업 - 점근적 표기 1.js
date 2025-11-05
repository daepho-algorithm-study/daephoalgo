const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  // .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);
/*
빅오 표기법의 수학적 형태를 이해하는 문제
f(n) = a_1 * n + a_0
g(n) = c * n
양의 정수 c, n_0가 주어질 경우 O(n)의 정의를 만족하는지 판별하는 문제
f(n)은 선형 함수(차수가 1)이기 때문에 n_0 을 n에 대입했을때 식이 성립한다면
n_0 이후의 큰 값들은 식을 모두 만족시킬 수 있음을 보이면 됨
*/
function solution(input) {
  const a1 = input[0][0], a0 = input[0][1];
  const c = input[1];
  const n0 = input[2];

  // 주의할 점: a0의 범위는 절댓값으로 명시했기 때문에 -100 ~ 100임
  // 원래대로라면 f(n)의 기울기인 a1보다 g(n)의 기울기인 c가 더 작으면 항상 식이 성립될 수 없는데
  // a0가 음수라면 a1 > c 이더라도 n0를 대입했을 때 식이 성립된다고 오판할 수 있음
  if (a1 > c) return 0;

  if (a1 * n0 + a0 <= c * n0) return 1;
  else return 0;
}

console.log(solution(input));
