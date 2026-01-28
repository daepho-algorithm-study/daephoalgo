const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, start, target) {
  
  // 나이트가 이동할 수 있는 8가지 방향
  const nightMove = [
    [-1, -2],
    [-2, -1],
    [-2, 1],
    [-1, 2],
    [1, -2],
    [2, -1],
    [1, 2],
    [2, 1],
  ];
  /*
  BFS depth 관리 방식 (원래 풀이)
  
  let cnt = 0; // 이동 횟수

  // 시작과 목표가 같으면 0 반환
  if (start === target) return cnt;

  // 방문 여부 체크 배열
  const visited = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => false)
  );

  // BFS 레벨 단위 큐
  const q = [[start]];

  while (q.length) {
    const curcycle = q.shift();   // 현재 이동 횟수에서의 좌표들
    const nextcycle = [];         // 다음 이동 횟수에서의 좌표들

    while (curcycle.length) {
      const [ci, cj] = curcycle.shift();

      if (visited[ci][cj]) continue;
      visited[ci][cj] = true;

      // 목표 위치 도달 시 이동 횟수 반환
      if (ci === target[0] && cj === target[1]) return cnt;

      // 나이트 이동 가능한 위치 탐색
      for (const [ni, nj] of nightMove) {
        const nextI = ci + ni;
        const nextJ = cj + nj;

        // 범위 밖이거나 이미 방문한 경우 스킵
        if (
          nextI < 0 || nextI >= N ||
          nextJ < 0 || nextJ >= N ||
          visited[nextI][nextJ]
        ) continue;

        nextcycle.push([nextI, nextJ]);
      }
    }

    // 다음 레벨이 있으면 큐에 추가
    if (nextcycle.length) q.push(nextcycle);

    cnt++; // 이동 횟수 증가
  }
  */

    // 각 칸까지의 최단 거리 저장 (-1이면 미방문)
    // visited를 잘 활용하자
  const dist = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => -1)
  );

  // BFS용 큐
  const q = [];
  let head = 0; // shift 안쓰고 head 포인터로 큐 관리

  // 시작 위치 초기화
  q.push(start);
  dist[start[0]][start[1]] = 0;

  while (head < q.length) {
    const [x, y] = q[head++];

    // 목표 지점 도착 시 최단 거리 반환
    if (x === target[0] && y === target[1]) {
      return dist[x][y];
    }

    // 이동 가능한 모든 방향 탐색
    for (const [dx, dy] of nightMove) {
      const nx = x + dx;
      const ny = y + dy;

      // 범위 밖이거나 이미 방문한 경우 스킵
      if (
        nx < 0 || nx >= N ||
        ny < 0 || ny >= N ||
        dist[nx][ny] !== -1
      ) continue;

      // 거리 갱신 후 큐에 추가
      dist[nx][ny] = dist[x][y] + 1;
      q.push([nx, ny]);
    }
  }

  return -1; // 도달 불가능한 경우
}


const T = input[0][0];

for (let i = 0; i < T; i++) {
  const N = input[i * 3 + 1][0];
  const start = input[i * 3 + 2];
  const target = input[i * 3 + 3];
  console.log(solution(N, start, target));
}
