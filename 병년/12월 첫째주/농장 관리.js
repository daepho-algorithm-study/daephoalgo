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
  // 좌표 탐색 조건은 하나의 좌표 차이기 때문에 대각선도 모두 고려해야 함
  const dx = [-1, 1, 0, 0, -1, 1, 1, -1];
  const dy = [0, 0, -1, 1, -1, 1, -1, 1];
  // 방문 체크 배열
  const visited = Array.from({ length: N }, () => Array(M).fill(false));
  // 현재 산봉우리 높이와 다음 산봉우리 높이를 체크하기 위한 변수
  let check = false;
  // dfs 시작
  const dfs = (x, y) => {
    // 방문 체크
    visited[x][y] = true;
    // 8방 탐색
    for (let k = 0; k < 8; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      // 경계 조간
      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        // 만약 다음 산봉우리가 현재 산봉우리보다 높다면 유효하지 않은 산봉우리
        if (arr[x][y] < arr[nx][ny]) check = false;
        // 방문하지 않았고 다음 높이가 현재 위치와 같다면 재귀 호출
        if (!visited[nx][ny] && arr[x][y] === arr[nx][ny]) {
          dfs(nx, ny);
        }
      }
    }
  };
  let cnt = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (!visited[i][j]) {
        // 초기 check 값 설정
        check = true;
        dfs(i, j);
        // check 값이 true 라면(산봉우리 탐색 완료) cnt 추가
        check ? cnt++ : "";
      }
    }
  }
  console.log(cnt);
};

solution(input);
