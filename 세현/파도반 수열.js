const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(T, cases) {
  // 메모이제이션 배열
  const triangles = Array.from({length: 101}, () => 0);

  // 초기값 설정
  triangles[1] = triangles[2] = triangles[3] = 1;

  // 점화식: f(n) = f(n-3) + f(n-2)
  for (let i = 4; i <= 100; i++) {
    triangles[i] = triangles[i-3] + triangles[i-2];
  }

  // 결과 출력
  for (const N of cases) {
    console.log(triangles[N])
  }

}

solution(input[0], input.slice(1));
