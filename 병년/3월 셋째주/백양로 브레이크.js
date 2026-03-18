const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);
  const dist = Array.from({ length: N }, () => Array(N).fill(Infinity));
  /**
   * 우리가 구하고자 하는 것은 일방 통행 인 길을 양방향 통행으로 바꿔야 하는 것임
   * 따라서 입력값이 0이 들어오면 그 길은 일방 통행이라는 의미 이므로 반대 방향의 길에
   * 비용을 넣어줘야 함
   */
  for (let i = 0; i < N; i++) {
    dist[i][i] = 0;
  }
  for (let i = 0; i < M; i++) {
    const [u, v, b] = input[idx++].split(" ").map(Number);
    if (b === 0) {
      dist[u - 1][v - 1] = 0;
      dist[v - 1][u - 1] = 1;
    } else {
      dist[u - 1][v - 1] = 0;
      dist[v - 1][u - 1] = 0;
    }
  }
  /**
   * dist[i][j]는 i에서 j로 이동할 때
   * 최소 몇 개의 도로 방향을 변경해야 하는지를 의미한다.
   */
  const floyd = (dist) => {
    for (let k = 0; k < N; k++) {
      for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
          dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  };

  floyd(dist);
  const K = Number(input[idx++]);
  /**
   * 그 이후 dist 배열에서 s, e에 해당하는 값만 출력하면 끝
   */
  for (let _ = 0; _ < K; _++) {
    const [s, e] = input[idx++].split(" ").map(Number);
    console.log(dist[s - 1][e - 1]);
  }
};
solution(input);
