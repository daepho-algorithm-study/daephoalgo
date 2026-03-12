const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  // 플루이드 워셜 핵심 k라는 노드를 경유지로 사용할 때 더 짧아지는가?
  let idx = 0;
  const N = Number(input[idx++]);
  const M = Number(input[idx++]);
  // 거리 배열 선언
  const dist = Array.from({ length: N + 1 }, () =>
    Array(N + 1).fill(Number.MAX_SAFE_INTEGER / 3),
  );

  // 2차원의 거리 배열에 현재 값 미리 0으로 초기화
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      if (i === j) dist[i][j] = 0;
    }
  }

  // 출발점, 도착지, 비용 입력
  for (let i = 0; i < M; i++) {
    const [a, b, cost] = input[idx++].split(" ").map(Number);
    // 동일한 지점이 존재하기 때문에 그 중 가장 작은 값 입력
    dist[a][b] = Math.min(dist[a][b], cost);
  }

  // k 번 노드를 경유하는 경우와 현재 값에서 가장 작은 값 입력
  for (let k = 1; k <= N; k++) {
    for (let i = 1; i <= N; i++) {
      for (let j = 1; j <= N; j++) {
        // 여기서 dist 배열이 결국 i 에서 j 로 가는 값의 비용이기 때문에 k 를 경유한 애들과 비교해주는 것
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (let i = 1; i < dist.length; i++) {
    const row = [];
    for (let j = 1; j < dist[0].length; j++) {
      if (dist[i][j] === Infinity) continue;
      row.push(dist[i][j]);
    }
    console.log(row.join(" "));
  }
};
solution(input);
