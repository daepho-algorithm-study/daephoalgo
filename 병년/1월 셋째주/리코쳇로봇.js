const solution = (board) => {
  const n = board.length;
  const m = board[0].length;
  board = board.map((row) => row.split(""));

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const visited = Array.from({ length: n }, () => Array(m).fill(false));

  const queue = [];

  // 시작 지점 찾기
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (board[i][j] === "R") {
        queue.push([i, j, 0]); // dist = 0
        visited[i][j] = true;
      }
    }
  }

  let head = 0;

  while (queue.length > head) {
    const [x, y, dist] = queue[head++];

    for (let k = 0; k < 4; k++) {
      let nx = x;
      let ny = y;

      // 한 방향으로 끝까지 이동
      while (
        nx + dx[k] >= 0 &&
        nx + dx[k] < n &&
        ny + dy[k] >= 0 &&
        ny + dy[k] < m &&
        board[nx + dx[k]][ny + dy[k]] !== "D"
      ) {
        nx += dx[k];
        ny += dy[k];
      }

      // 한 칸도 이동하지 못한 경우는 무시
      if (nx === x && ny === y) continue;

      // 목표 지점 도달
      if (board[nx][ny] === "G") return dist + 1;

      if (!visited[nx][ny]) {
        // 방문 처리
        visited[nx][ny] = true;
        // dist 추가 및 다음 좌표 탐색
        queue.push([nx, ny, dist + 1]);
      }
    }
  }

  return -1;
};
