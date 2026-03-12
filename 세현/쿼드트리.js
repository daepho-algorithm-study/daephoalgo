const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, tile) {

  // xs: 시작점 가로좌표, ys: 시작점 세로좌표, xe: 끝점 가로좌표, ye: 끝점 세로좌표
  const devide = (xs, ys, xe, ye) => {

    const current = tile[ys][xs] // 맨 처음 값을 기준으로 계속 비교할 것

    for (let i = ys; i < ye; i++) {     //세로 검사
      for (let j = xs; j < xe; j++) {   //가로 검사

        if (tile[i][j] !== current) {   // 값이 다르면 나눠야 함
          const m = (xe - xs) / 2;      // 중간값 설정

          const q1 = devide(xs+m, ys, xe, ys+m);   // 1사분면
          const q2 = devide(xs, ys, xs+m, ys+m);   // 2사분면
          const q3 = devide(xs, ys+m, xs+m, ye);   // 3사분면
          const q4 = devide(xs+m, ys+m, xe, ye);   // 4사분면
  
          return `(${q2}${q1}${q3}${q4})`; // 순서는 2-1-3-4 사분면 순으로 해야 함
        }
      }
    }

    return current;
  }

  let answer = devide(0, 0, N, N);

  return answer;
}

const N = Number(input[0]);
const tile = input.slice(1).map((line) => line.split("").map(Number));

console.log(solution(N, tile));
