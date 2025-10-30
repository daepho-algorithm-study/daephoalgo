const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [M, N, H] = input[0].split(" ").map(Number);
  const arr = [];
  let idx = 1;

  // 3차원 배열 생성
  for (let h = 0; h < H; h++) {
    const layer = [];
    for (let n = 0; n < N; n++) {
      layer.push(input[idx++].split(" ").map(Number));
    }
    arr.push(layer);
  }

  const dx = [-1, 1, 0, 0, 0, 0];
  const dy = [0, 0, -1, 1, 0, 0];
  const dz = [0, 0, 0, 0, -1, 1];
  const queue = [];

  // 초기 익은 토마토 위치 큐에 추가
  for (let h = 0; h < H; h++) {
    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (arr[h][n][m] === 1) queue.push([h, n, m]);
      }
    }
  }

  let head = 0

  while (queue.length > head) {
    const [z, x, y] = queue[head++];

    for (let i = 0; i < 6; i++) {
      const nz = z + dz[i];
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nz && nz < H && 0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[nz][nx][ny] === 0) {
          arr[nz][nx][ny] = arr[z][x][y] + 1;
          queue.push([nz, nx, ny]);
        }
      }
    }
  }

  // 결과 계산
  let result = 0;
  for (let h = 0; h < H; h++) {
    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (arr[h][n][m] === 0) {
          console.log(-1);
          return;
        }
        result = Math.max(result, arr[h][n][m]);
      }
    }
  }

  console.log(result - 1);
};

solution(input);
