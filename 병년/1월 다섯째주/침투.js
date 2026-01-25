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
  const [M, N] = input[0].split(" ").map(Number);
  const arr = [];
  // 방문 배열
  const visited = Array.from({ length: M }, () => Array(N).fill(false));
  for (let i = 0; i < M; i++) {
    arr.push(input[i + 1].split("").map(Number));
  }
  // 델타 배열 추가
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  // dfs 탐색
  const dfs = (x, y) => {
    // 방문 체크
    visited[x][y] = true;
    // 끝까지 내려갔으면 바로 true 반환
    if (x === M - 1) return true;
    for (let k = 0; k < 4; k++) {
      // 델타 탐색
      let nx = x + dx[k];
      let ny = y + dy[k];
      // 경계에 도달하지 않았으면
      if (0 <= nx && nx < M && 0 <= ny && ny < N) {
        // 아직 방문하지 않았고, 침투 가능한 곳이라면
        if (!visited[nx][ny] && arr[nx][ny] === 0) {
          // dfs 탐색 및 만약 true 반환하면 그대로 true 반환해서 끝내기
          if (dfs(nx, ny)) return true;
        }
      }
    }
    // 침투 못하면 false 반환
    return false;
  };

  for (let j = 0; j < N; j++) {
    // 위에서 시작 고정이기 때문에 j 값만 알면 됨
    // 아직 방문하지 않았고, 침투 가능하다면
    if (!visited[0][j] && arr[0][j] === 0) {
      // dfs 탐색 및 결과 파싱
      if (dfs(0, j)) {
        console.log("YES");
        return;
      }
    }
  }

  console.log("NO");
};
solution(input);
