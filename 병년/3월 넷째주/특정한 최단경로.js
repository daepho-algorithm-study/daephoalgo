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
class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(value) {
    this.heap.push(value);
    this.bubbleUp();
  }

  pop() {
    if (this.heap.length === 1) return this.heap.pop();
    const top = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();
    return top;
  }

  bubbleUp() {
    let idx = this.heap.length - 1;
    while (idx > 0) {
      let parent = Math.floor((idx - 1) / 2);
      if (this.heap[parent][0] <= this.heap[idx][0]) break;
      [this.heap[parent], this.heap[idx]] = [this.heap[idx], this.heap[parent]];
      idx = parent;
    }
  }

  bubbleDown() {
    let idx = 0;
    const length = this.heap.length;

    while (true) {
      let left = idx * 2 + 1;
      let right = idx * 2 + 2;
      let smallest = idx;

      if (left < length && this.heap[left][0] < this.heap[smallest][0]) {
        smallest = left;
      }
      if (right < length && this.heap[right][0] < this.heap[smallest][0]) {
        smallest = right;
      }
      if (smallest === idx) break;

      [this.heap[idx], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[idx],
      ];
      idx = smallest;
    }
  }

  isEmpty() {
    return this.heap.length === 0;
  }
}
// // 플로이드 워셜 풀이 100% 시간초과 날 거임 안나네? 왜지?
// const solution = (input) => {
//   let idx = 0;
//   const [N, E] = input[idx++].split(" ").map(Number);
//   const dist = Array.from({ length: N }, () => Array(N).fill(Infinity));
//   for (let i = 0; i < N; i++) {
//     dist[i][i] = 0;
//   }
//   for (let i = 0; i < E; i++) {
//     const [a, b, c] = input[idx++].split(" ").map(Number);
//     dist[a - 1][b - 1] = c;
//     dist[b - 1][a - 1] = c;
//   }

//   for (let k = 0; k < N; k++) {
//     for (let i = 0; i < N; i++) {
//       for (let j = 0; j < N; j++) {
//         dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
//       }
//     }
//   }

//   const [v1, v2] = input[idx++].split(" ").map(Number);

//   const a = v1 - 1;
//   const b = v2 - 1;
//   let answer1 = dist[0][a] + dist[a][b] + dist[b][N - 1];
//   let answer2 = dist[0][b] + dist[b][a] + dist[a][N - 1];
//   let answer = Math.min(answer1, answer2);
//   console.log(answer !== Infinity ? answer : -1);
// };
// solution(input);
const solution = (input) => {
  let idx = 0;
  const [N, E] = input[idx++].split(" ").map(Number);
  const graph = Array.from({ length: N }, () => []);
  for (let i = 0; i < E; i++) {
    const [a, b, cost] = input[idx++].split(" ").map(Number);
    graph[a - 1].push([b - 1, cost]);
    graph[b - 1].push([a - 1, cost]);
  }
  const dijkstra = (start) => {
    const dist = Array.from({ length: N }, () => Infinity);
    const q = new MinHeap();
    dist[start] = 0;
    q.push([0, start]);

    while (!q.isEmpty()) {
      const [curDist, now] = q.pop();

      if (dist[now] < curDist) continue;

      for (const [next, cost] of graph[now]) {
        const nextDist = curDist + cost;
        if (nextDist < dist[next]) {
          dist[next] = nextDist;
          q.push([nextDist, next]);
        }
      }
    }
    return dist;
  };
  const [a, b] = input[idx++].split(" ").map(Number);
  const v1 = a - 1;
  const v2 = b - 1;
  let a0 = dijkstra(0);
  let a1 = dijkstra(a - 1);
  let a2 = dijkstra(b - 1);
  let case1 = a0[v1] + a1[v2] + a2[N - 1];
  let case2 = a0[v2] + a2[v1] + a1[N - 1];

  const answer = Math.min(case1, case2);
  console.log(answer === Infinity ? -1 : answer);
};
solution(input);
