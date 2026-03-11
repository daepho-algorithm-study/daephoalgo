const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, tile) {
  
  let [pone_cnt, zero_cnt, mone_cnt] = [0, 0, 0]

  // xs: 시작점 가로좌표, ys: 시작점 세로좌표, xe: 끝점 가로좌표, ye: 끝점 세로좌표
  const devide = (xs, ys, xe, ye) => {

    const current = tile[ys][xs] // 맨 처음 값을 기준으로 계속 비교할 것

    for (let i = ys; i < ye; i++) {     //세로 검사
      for (let j = xs; j < xe; j++) {   //가로 검사

        if (tile[i][j] !== current) {   // 값이 다르면 나눠야 함
          const size = (xe - xs) / 3;
          const xm1 = xs + size;     // 3분의 1 x지점
          const xm2 = xs + size*2;  // 3분의 2 x지점
          const ym1 = ys + size;     // 3분의 1 y지점
          const ym2 = ys + size*2;  // 3분의 2 y지점          
          
          devide(xs, ys, xm1, ym1);   // 9분의 1 재귀
          devide(xm1, ys, xm2, ym1);  // 9분의 2 재귀
          devide(xm2, ys, xe, ym1);   // 9분의 3 재귀
          devide(xs, ym1, xm1, ym2);  // 9분의 4 재귀
          devide(xm1, ym1, xm2, ym2); // 9분의 5 재귀
          devide(xm2, ym1, xe, ym2);  // 9분의 6 재귀
          devide(xs, ym2, xm1, ye);   // 9분의 7 재귀
          devide(xm1, ym2, xm2, ye);  // 9분의 8 재귀
          devide(xm2, ym2, xe, ye);   // 9분의 9 재귀
          
          return;
        }
      }
    }

    if (current === -1) {
        mone_cnt++;
    } else if (current === 0) {
        zero_cnt++;
    } else {
        pone_cnt++;
    }
 
    return;
  }

  devide(0, 0, N, N);

  return `${mone_cnt}\n${zero_cnt}\n${pone_cnt}`;
}

const N = Number(input[0])
const tile = input.slice(1).map((line) => line.split(" ").map(Number));
console.log(solution(N, tile));
