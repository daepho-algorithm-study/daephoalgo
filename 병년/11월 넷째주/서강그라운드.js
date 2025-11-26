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
  let idx = 0;
  let result = 0;
  const [N, M, R] = input[idx++].split(" ").map(Number);
  // 정점과 간선 비용을 저장할 그래프 생성
  const graph = Array.from({ length: N + 1 }, () => []);
  // 0을 맨 앞에 채우고 1번 부터 받기 해당 문제는 1번 부터 시작하기에 인덱스로 접근하기 쉽도록 
  const items = [0, ...input[idx++].split(" ").map(Number)];

  for (let i = 0; i < R; i++) {
    // 정점 정보, 간선, 비용
    const [a, b, c] = input[idx++].split(" ").map(Number);
    // 양방향 그래프 
    graph[a].push({ to: b, cost: c });
    graph[b].push({ to: a, cost: c });
  }
  // 다익스트라 기본 코드
  const dijkstra = (dist, visited) => {
    for (let i = 0; i < N; i++) {
      let now = -1;

      let min = Infinity;

      for (let j = 1; j <= N; j++) {
        if (!visited[j] && dist[j] < min) {
          min = dist[j];
          now = j;
        }
      }
      if (now === -1) break;
      visited[now] = true;

      for (const next of graph[now]) {
        const newCost = dist[now] + next.cost;

        if (newCost < dist[next.to]) {
          dist[next.to] = newCost;
        }
      }
    }
  };
  // 시작점과 끝점이 정해져있지 않기 때문에 모든 정점에 대해 다익스트라 수행 
  for (let i = 1; i < N + 1; i++) {
    // 거리를 저장할 배열 
    const dist = Array(N + 1).fill(Infinity);
    // 방문체크 배열
    const visited = Array(N + 1).fill(false);
    // 현재 노드 거리 초기화
    dist[i] = 0;
    // 해당 노드로 다익스트라 수행
    dijkstra(dist, visited);
    let sm = 0;
    // 해당 노드에서 갈 수 있는 거리 계산
    for (let j = 1; j < N + 1; j++) {
      // 해당 정점의 거리가 M(수색 범위) 보다 작은 경우
      if (dist[j] <= M) {
        // sm에 합산
        sm += items[j];
      }
    }
    // 갈 수 있는 값 최대로 갱신
    result = Math.max(result, sm);
  }
  console.log(result);
};

solution(input);
