const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/);
//   .map((e) => Number(e));
// .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, maze) {
  let cnt = 0; // 이동한 거리(층 수)

  // 방문 여부 저장 배열
  const visited = Array.from({ length: N }, () =>
    Array.from({ length: M }, () => false)
  );

  // 상, 좌, 하, 우 이동 방향
  const delta = [
    [-1, 0],
    [0, -1],
    [1, 0],
    [0, 1],
  ];

  // BFS 레벨 단위로 관리하는 큐
  const q = [[[0, 0]]];

  while (q.length) {
    const curcycle = q.shift(); // 현재 거리에서 방문할 좌표들
    const nextcycle = [];      // 다음 거리에서 방문할 좌표들

    while (curcycle.length) {
      const [ci, cj] = curcycle.shift();

      if (visited[ci][cj]) continue;
      visited[ci][cj] = true;

      // 도착 지점에 도달하면 현재 이동 횟수 + 1 반환
      if (ci === N - 1 && cj === M - 1) return cnt + 1;

      // 네 방향 탐색
      for (const [ni, nj] of delta) {
        const nextI = ci + ni;
        const nextJ = cj + nj;

        // 범위 밖, 방문함, 벽이면 스킵
        if (
          nextI < 0 || nextI >= N ||
          nextJ < 0 || nextJ >= M ||
          visited[nextI][nextJ] ||
          maze[nextI][nextJ] === 0
        ) continue;

        nextcycle.push([nextI, nextJ]);
      }
    }

    // 다음 레벨이 있으면 큐에 추가
    if (nextcycle.length) q.push(nextcycle);

    cnt++; // 거리 증가
  }

  return cnt;
}

const lineone = input[0].split(" ").map(Number);
const [N, M] = lineone;
const maze = input.slice(1).map((line) => line.split("").map(Number));
console.log(solution(N, M, maze));
