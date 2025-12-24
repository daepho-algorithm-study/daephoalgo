function solution(N, road, K) {
  var answer = 0;
  const graph = Array.from({ length: N + 1 }, () => []);

  for (let i = 0; i < road.length; i++) {
    const [a, b, c] = road[i];
    graph[a].push({ to: b, cost: c });
    graph[b].push({ to: a, cost: c });
  }

  const dist = Array(N + 1).fill(Infinity);
  const visited = Array(N + 1).fill(false);

  dist[1] = 0;

  const dijkstra = () => {
    let result = 0;
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
    for (const d of dist) {
      if (d <= K) result++;
    }
    return result;
  };
  answer = dijkstra();
  return answer;
}
