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
  const [N, M] = input[0].split(" ").map(Number);
  const arr = input.slice(1).map((line) => line.split(" ").map(Number));
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  // BFS 로 덩어리 찾기
  const bfs = () => {
    // 공기의 좌표를 찾기 위한 배열
    const visited = Array.from({ length: N }, () => Array(M).fill(false));
    // 공기 표시
    visited[0][0] = true;
    // 공기에 인접한 다른 공기들을 찾기 위한 queue 선언
    let queue = [[0, 0]];
    let head = 0;

    while (queue.length > head) {
      const [x, y] = queue[head++];

      for (let k = 0; k < 4; k++) {
        let nx = x + dx[k];
        let ny = y + dy[k];
        // 인접한 칸 중 공기가 있을 경우
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
          // 아직 체크 안되어 있는 공기라면
          if (!visited[nx][ny] && arr[nx][ny] === 0) {
            // 공기 체크 후 queue에 추가
            visited[nx][ny] = true;
            queue.push([nx, ny]);
          }
        }
      }
    }
    // 공기 배열 반환
    return visited;
  };
  // 공기 배열을 매개변수로 받는 녹이기 함수
  const melt = (visited) => {
    // 원본 배열이 아닌 새로운 배열 선언
    const melted = [];
    // 2중 반복을 통한 개수 카운팅
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        // 현재 위치가 치즈라면
        if (arr[i][j] === 1) {
          // 공기를 셀 카운팅 변수 선언
          let cnt = 0;
          for (let k = 0; k < 4; k++) {
            let nx = i + dx[k];
            let ny = j + dy[k];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
              // 인접한 칸이 공기라면
              if (visited[nx][ny]) {
                // 공기 개수 추가
                cnt++;
              }
            }
          }
          // 녹인 배열에 좌표값 추가
          if (cnt >= 2) {
            melted.push([i, j]);
          }
        }
      }
    }
    // 반복문을 통한 배열 값 변경
    for (const [x, y] of melted) arr[x][y] = 0;
  };

  let time = 0;
  while (true) {
    // 공기에 해당하는 좌표 찾기
    let visited = bfs();
    // 공기를 통한 치즈 녹이기
    melt(visited);
    time++;
    // 원본 배열 복사해서 모든 요소 값 검사하기
    if (arr.flat().every((v) => v === 0)) break;
  }
  console.log(time);
};
solution(input);
