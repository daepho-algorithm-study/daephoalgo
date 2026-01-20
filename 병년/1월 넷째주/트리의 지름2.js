const { dirxml } = require("console");
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
  const N = Number(input[idx++]);

  // graph[u] = [{ to, cost }]
  const graph = Array.from({ length: N + 1 }, () => []);

  for (let i = 0; i < N; i++) {
    const data = input[idx++].split(" ").map(Number);

    const from = data[0];

    for (let j = 1; j < data.length - 1; j += 2) {
      const to = data[j];
      const cost = data[j + 1];

      if (to === -1) break;
      graph[from].push({ to, cost });
    }
  }

  const bfs = (x) => {
    let head = 0;
    let queue = [x];

    const dist = Array.from({ length: N + 1 }, () => -1);

    dist[x] = 0;

    while (head < queue.length) {
      const node = queue[head++];

      for (const { to, cost } of graph[node]) {
        if (dist[to] !== -1) continue;
        dist[to] = dist[node] + cost;
        queue.push(to);
      }
    }
    let next = x;
    let final = 0;
    for (let i = 1; i <= N; i++) {
      if (dist[i] > dist[next]) next = i;
    }
    final = dist[next];
    return { next, final };
  };

  const { next: A } = bfs(1);
  const { final: result } = bfs(A);
  console.log(result);
};
solution(input);
