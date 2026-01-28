const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, edges) {
  // 특정 정점에서 시작하는 DFS
  const dfs = (x) => {
    if (visited[x]) return;

    visited[x] = true;

    // 인접한 정점 재귀 탐색
    for (const v of graph[x]) {
      if (visited[v]) continue;
      dfs(v);
    }
  };

  let conected = 0; // 연결 요소 개수

  // 인접 리스트 그래프
  const graph = Array.from({ length: N + 1 }, () => []);

  // 방문 여부 배열
  const visited = Array.from({ length: N + 1 }, () => false);

  // 양방향 그래프 구성
  for (const edge of edges) {
    graph[edge[0]].push(edge[1]);
    graph[edge[1]].push(edge[0]);
  }

  // 모든 정점을 돌며 아직 방문하지 않은 곳에서 DFS 시작
  for (let i = 1; i <= N; i++) {
    if (!visited[i]) {
      dfs(i);
      conected++; // 하나의 연결 요소 발견
    }
  }

  return conected;
}

console.log(solution(input[0][0], input[0][1], input.slice(1)));
