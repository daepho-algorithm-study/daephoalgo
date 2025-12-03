const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);

  const graph = Array.from({ length: N + 1 }, () => []);

  for (let i = 0; i < N - 1; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    graph[a].push({ to: b, cost: c });
    graph[b].push({ to: a, cost: c });
  }

  for (let i = 0; i < M; i++) {
    const [start, end] = input[idx++].split(" ").map(Number);

    // const bfs = () => {
    //   const visited = Array.from({ length: N }, () => false);
    //   let queue = [[start, 0]];
    //   visited[start] = true;

    //   let head = 0;
    //   while (queue.length > head) {
    //     const [cur, dist] = queue[head++];

    //     if (cur === end) return dist;

    //     for (const { to, cost } of graph[cur]) {
    //       if (!visited[to]) {
    //         visited[to] = true;
    //         queue.push([to, dist + cost]);
    //       }
    //     }
    //   }
    //   return 0;
    // };
    const visited = Array.from({ length: N }, () => false);
    let answer = 0;
    const dfs = (cur, dist) => {
      if (cur === end) {
        answer = dist;
        return;
      }

      visited[cur] = true;

      for (const { to, cost } of graph[cur]) {
        if (!visited[to]) {
          dfs(to, dist + cost);
        }
      }
    };

    dfs(start, 0);
    console.log(answer);
  }
};
solution(input);
