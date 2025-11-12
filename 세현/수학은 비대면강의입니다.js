const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  let a = input[0], b = input[1], c = input[2], d = input[3], e = input[4], f = input[5];
  // 브루트포스 말고 수학으로 품
  // 문제에서 유일한 해가 존재한다고 박혀있으므로 가능함
  // 두 연립방정식은 그래프로 나타냈을 때 선형 방정식으로 나타낼 수 있음
  // 그리고 유일한 해를 만족하려면 두 선은 반드시 교차해서 만나야 함 (만나는 지점이 해)
  // 때문에 ec-bf, ea-bd, af-dc, ae-db 는 절대 0이 나올 수 없음
  // 0이 나오면 기울기가 같다는 뜻인데 그러면 해가 무수히 많거나 해가 없는 경우임
  // 따라서 식을 정리하면 상수로 표현되는 x, y를 구할 수 있음

  const jax = e*c - b*f;
  const mox = e*a - b*d;
  const jay = a*f - d*c;
  const moy = a*e - d*b;
  const x = jax / mox;
  const y = jay / moy;

  return [x, y];
}

console.log(solution(input).join(" "));
