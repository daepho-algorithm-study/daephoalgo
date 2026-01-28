const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, danji) {
  // 각 단지의 집 개수를 저장할 배열
  let danjiset = [];

  // 방문 여부 체크 배열
  const visited = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => false)
  );

  // 상, 좌, 하, 우 이동 방향
  const delta = [
    [-1, 0],
    [0, -1],
    [1, 0],
    [0, 1],
  ];

  // 단지 개수
  let danjicnt = 0;

  // 특정 좌표에서 시작하는 BFS
  const bfs = (i, j) => {
    if (visited[i][j]) return;

    const q = [[i, j]];
    let aptnum = 0; // 현재 단지의 집 수

    while (q.length) {
      const [ci, cj] = q.shift();

      if (visited[ci][cj]) continue;

      aptnum++;
      visited[ci][cj] = true;

      // 인접한 집 탐색
      for (const [ni, nj] of delta) {
        const nextI = ci + ni;
        const nextJ = cj + nj;

        // 범위 밖, 방문함, 집이 아닌 경우 스킵
        if (
          nextI < 0 || nextI >= N ||
          nextJ < 0 || nextJ >= N ||
          visited[nextI][nextJ] ||
          danji[nextI][nextJ] === 0
        ) continue;

        q.push([nextI, nextJ]);
      }
    }

    // 하나의 단지 탐색 완료
    danjicnt++;
    danjiset.push(aptnum);
  };

  // 전체 격자를 돌며 새로운 단지 탐색
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (visited[i][j] || danji[i][j] === 0) continue;
      bfs(i, j);
    }
  }

  // 집 개수 오름차순 정렬
  danjiset.sort((a, b) => a - b);

  return `${danjicnt}\n${danjiset.join("\n")}`;
}

const N = Number(input[0].join(""))
console.log(solution(N, input.slice(1)));
