function solution(n, edge) {
  var answer = 0;
  const graph = {};
  for (const [u, v] of edge) {
    if (!graph[u]) graph[u] = [];
    if (!graph[v]) graph[v] = [];

    graph[u].push(v);
    graph[v].push(u);
  }
  const queue = [[1, 1]];
  const visited = Array.from({ length: n + 1 }, () => false);
  const arr = Array.from({ length: n + 1 }, () => 0);
  arr[1] = 1;
  visited[1] = true;
  const bfs = () => {
    let head = 0;

    while (head < queue.length) {
      const [cur, depth] = queue[head++];

      arr[cur] = depth;
      for (let next of graph[cur]) {
        if (!visited[next]) {
          visited[next] = true;
          queue.push([next, depth + 1]);
        }
      }
    }
    const mx = Math.max(...arr);
    return arr.filter((value) => value === mx).length;
  };
  answer = bfs();

  return answer;
}
console.log(
  solution(6, [
    [3, 6],
    [4, 3],
    [3, 2],
    [1, 3],
    [1, 2],
    [2, 4],
    [5, 2],
  ]),
);
