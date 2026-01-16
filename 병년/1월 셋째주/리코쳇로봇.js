const solution = (board) => {
  const n = board.length;
  const m = board[0].length;
  board = board.map((row) => row.split(""));

  let answer = 0;
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const visited = Array.from({ length: n }, () => Array(m).fill(false));

  const queue = [];

  const gCoord = [];

  // 시작 지점 찾기
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (board[i][j] === "R") {
        queue.push([i, j, 0]); // dist = 0
        visited[i][j] = true;
      }
      if (board[i][j] === "G") {
        gCoord.push(i, j);
      }
    }
  }
  // 먼저 도착지점 근처에 장애물이나 경계가 있는 지 체크
  const isPossible = (g) => {
    const [x, y] = g;

    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      // 도착지점이 경계에 인접해 있다면 true 반환
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) return true;

      // 도착지점이 장애물에 인접해 있어도 true 반환
      if (board[nx][ny] === "D") return true;
    }
    // 아니라면 false 반환
    return false;
  };
  // 체크
  const tiket = isPossible(gCoord);
  const bfs = () => {
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
  // 도착지점 체크했을 때 불가능 하다면 바로 -1 return
  if (!tiket) {
    return -1;
    // 아니라면 최단 경로 찾기
  } else {
    answer = bfs();
    return answer;
  }
};
