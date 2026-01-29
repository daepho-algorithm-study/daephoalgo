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
  const N = Number(input[0]);
  const arr = [];

  for (let i = 1; i <= N; i++) {
    arr.push(input[i].split(" ").map(Number));
  }
  // 방문 체크 배열
  const visited = Array.from({ length: N }, () => Array(N).fill(false));

  // dfs 탐색
  const dfs = (x, y) => {
    // 방문 체크
    visited[x][y] = true;
    // 점프가능한 칸의 수
    const jump = arr[x][y];
    // 만약 오른쪽 아래 끝에 도달하면 true 반환
    if (x === N - 1 && y === N - 1) {
      return true;
    }
    // 점프할 수 없으면 바로 false 반환
    if (jump === 0) return false;

    // 아래 부터 가보기
    const nx1 = x + jump;
    const ny1 = y;
    // 경계에 속해있고 아직 가보지 않았다면 아래로 가보기
    if (0 <= nx1 && nx1 < N && !visited[nx1][ny1]) {
      // 아래로 가다가 true 반환하면 그대로 true 반환해서 끝내기
      if (dfs(nx1, ny1)) return true;
    }

    // 오른쪽 가보기
    const nx2 = x;
    const ny2 = y + jump;

    // 경계에 속해있고 아직 가보지 않았다면 오른쪽으로 가보기
    if (0 <= ny2 && ny2 < N && !visited[nx2][ny2]) {
      // 오른쪽으로 가다가 true 반환하면 그대로 true 반환해서 끝내기
      if (dfs(nx2, ny2)) return true;
    }

    // 못 가면 false 반환
    return false;
  };

  // 좌표 0,0 부터 시작
  let answer = dfs(0, 0);
  console.log(answer ? "HaruHaru" : "Hing");
};

solution(input);
