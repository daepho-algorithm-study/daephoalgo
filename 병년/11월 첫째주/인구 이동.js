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
  const [N, L, R] = input[0].split(" ").map(Number);
  const arr = input.slice(1).map((line) => line.split(" ").map(Number));
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];
  const move = (union) => {
    // 연합의 인구 수 더하기
    let sum = 0;
    let len = union.length;
    for ([x, y] of union) {
      sum += arr[x][y];
    }
    let avg = Math.floor(sum / len);
    // 연합 인구 바꾸기
    for ([x, y] of union) {
      arr[x][y] = avg;
    }
  };

  const bfs = (i, j, visited) => {
    visited[i][j] = true;
    // queue 와 연합 배열 정의
    let queue = [[i, j]];
    let union = [[i, j]];
    let head = 0;

    while (queue.length > head) {
      const [x, y] = queue[head++];

      for (let k = 0; k < 4; k++) {
        const nx = x + dx[k];
        const ny = y + dy[k];

        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
          //인접한 곳의 절대값 계산
          const diff = Math.abs(arr[x][y] - arr[nx][ny]);
          // 절대값 기준 통과시
          if (L <= diff && diff <= R) {
            // 다음 좌표 큐에 넣고 연합 좌표에 추가
            queue.push([nx, ny]);
            union.push([nx, ny]);
            // 방문 체크
            visited[nx][ny] = true;
          }
        }
      }
    }
    return union;
  };
  let year = 0;
  while (true) {
    // 방문 체크 배열
    let visited = Array.from({ length: N }, () => Array(N).fill(false));
    // 인구 이동이 일어 날 수 있는 지 체크 변수
    let moved = false;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (!visited[i][j]) {
          // 연합 생성
          const union = bfs(i, j, visited);
          // 연합이 만들어졌으면
          if (union.length > 1) {
            // 이동 가능 체크 후
            moved = true;
            // 실제 이동
            move(union);
          }
        }
      }
    }
    // 이동이 일어나지 않으면 탈출
    if (!moved) break;
    // 해 증가
    year++;
  }
  console.log(year);
};

solution(input);
