const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");
const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }
  // 대각선을 고려한 델타 배열 할당
  const dx = [-1, 1, 0, 0, -1, 1, 1, -1];
  const dy = [0, 0, -1, 1, -1, 1, -1, 1];
  // 2차원 방문체크 배열
  const visited = Array.from({ length: N }, () => Array(M).fill(false));

  // dfs 함수
  const dfs = (x, y) => {
    // 현재 값 방문 처리
    visited[x][y] = true;
    let nx = 0;
    let ny = 0;
    // nx, ny 갱신
    for (let k = 0; k < 8; k++) {
      nx = x + dx[k];
      ny = y + dy[k];
      // 범위에 벗어나지 않고 방문하지 않았으며 배열의 원소가 1이라면
      if (
        0 <= nx &&
        nx < N &&
        0 <= ny &&
        ny < M &&
        !visited[nx][ny] &&
        arr[nx][ny] === 1
      ) {
        // 방문체크 후 dfs 수행
        visited[nx][ny] = true;
        dfs(nx, ny);
      }
    }
  };
  let cnt = 0;
  // 배열 원소에 대해 반복
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      // 아직 방문하지 않았고 현재 배열의 원소가 1이라먄 dfs 수행 후 cnt 증가
      if (!visited[i][j] && arr[i][j] === 1) {
        dfs(i, j);
        cnt += 1;
      }
    }
  }
  console.log(cnt);
};
solution(input);
