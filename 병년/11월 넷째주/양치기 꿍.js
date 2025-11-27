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
  const arr = [];
  const [R, C] = input[idx++].split(" ").map(Number);
  for (let i = 0; i < R; i++) {
    arr.push(input[idx++].split(""));
  }
  let v = 0;
  let k = 0;
  // 델타 배열
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];
  // 방문 체크용 2차원 배열
  const visited = Array.from({ length: R }, () => Array(C).fill(false));
  // dfs 함수
  const dfs = (x, y) => {
    // 만약 현재 원소가 v 라면 v 값 증가(늑대)
    if (arr[x][y] === "v") v++;
    // k 라면 k 값 증가(양)
    else if (arr[x][y] === "k") k++;
    // 방문 체크
    visited[x][y] = true;
    // 델타 탐색
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      // 범위에 벗어나지 않고 방문하지 않았으며 울타리가 아니라면
      if (
        0 <= nx &&
        nx < R &&
        0 <= ny &&
        ny < C &&
        !visited[nx][ny] &&
        arr[nx][ny] != "#"
      ) {
        // dfs 수행
        dfs(nx, ny);
      }
    }
  };
  // 결과값 저장 배열
  let total = [0, 0];
  // 2차원 배열 반복
  for (let i = 0; i < R; i++) {
    for (let j = 0; j < C; j++) {
      // 방문하지 않았고 울타리가 아니라면
      if (!visited[i][j] && arr[i][j] !== "#") {
        // dfs 수행
        dfs(i, j);
        // dfs 수행 종료후 나왔을 때 양이 더 많다면 양에 합산
        if (k > v) total[0] += k;
        // 그 외의 경우라면 늑대에 합산
        else total[1] += v;
        // 새롭게 탐색할 수 있도록 늑대와 양 값 초기화
        v = 0;
        k = 0;
      }
    }
  }
  console.log(total.join(" "));
};
solution(input);
