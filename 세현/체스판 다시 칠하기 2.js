const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  // .map((e) => Number(e));
.map((line) => line.split(" "));

// console.log(input);

function solution(N, M, K, Board) {
  // startB[i][j]: (1,1)~(i,j) 범위에서 "B로 시작하는 체스판" 기준 잘못 칠해진 칸 수 (2D 누적합)
  // startW[i][j]: 동일 범위에서 "W로 시작하는 체스판" 기준 잘못 칠해진 칸 수
  const startB = Array.from({length: N+1}, () => 
    Array.from({length: M+1}, () => 0)
  );

  const startW = Array.from({length: N+1}, () => 
    Array.from({length: M+1}, () => 0)
  );

  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= M; j++) {

      // (i+j) % 2 === 0이면 B로 시작하는 체스판에서 해당 칸은 'B'가 정답
      if ((i+j)%2 === 0) {

        if (Board[i-1][j-1] === 'B') {
          // 정답 칸이 B인데 실제로 B → startW에 오류 +1 (W 시작 기준엔 틀림)
          startW[i][j] = startW[i-1][j] + startW[i][j-1] - startW[i-1][j-1] + 1;
          startB[i][j] = startB[i-1][j] + startB[i][j-1] - startB[i-1][j-1];
        } else {
          // 정답 칸이 B인데 실제로 W → startB에 오류 +1
          startW[i][j] = startW[i-1][j] + startW[i][j-1] - startW[i-1][j-1];
          startB[i][j] = startB[i-1][j] + startB[i][j-1] - startB[i-1][j-1] + 1;
        }
      } else {
        // (i+j) % 2 !== 0이면 B로 시작하는 체스판에서 해당 칸은 'W'가 정답
        if (Board[i-1][j-1] === 'B') {
          // 정답이 W인데 실제로 B인 경우 → startB에 오류 +1
          startW[i][j] = startW[i-1][j] + startW[i][j-1] - startW[i-1][j-1];
          startB[i][j] = startB[i-1][j] + startB[i][j-1] - startB[i-1][j-1] + 1;
        } else {
          // 정답이 W인데 실제로 W인 경우 → startW에 오류 +1
          startW[i][j] = startW[i-1][j] + startW[i][j-1] - startW[i-1][j-1] + 1;
          startB[i][j] = startB[i-1][j] + startB[i][j-1] - startB[i-1][j-1];
        }
      }
    }
  }

  let min_painting = Infinity;

  // K×K 부분 배열을 슬라이딩하며 최소 칠해야 할 칸 수 탐색
  for (let i = 1; i+K <= N+1; i++) {
    for (let j = 1; j+K <= M+1; j++) {

      // 2D 누적합으로 K×K 범위의 오류 칸 수 계산
      const paintingB = startB[i+K-1][j+K-1] - startB[i-1][j+K-1] - startB[i+K-1][j-1] + startB[i-1][j-1];
      const paintingW = startW[i+K-1][j+K-1] - startW[i-1][j+K-1] - startW[i+K-1][j-1] + startW[i-1][j-1];

      // B 시작, W 시작 중 더 적게 칠하는 경우 선택
      min_painting = Math.min(min_painting, paintingB, paintingW);
    }
  }

  return min_painting;
}

const [first, ...rest] = input;
const [N, M, K] = first.map(Number);
const Board = rest.map(row => row[0]);
console.log(solution(N, M, K, Board));
