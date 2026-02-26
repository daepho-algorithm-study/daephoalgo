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
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);
  // 1. 무향 그래프 정의
  const graph = Array.from({ length: N + 1 }, () => []);
  // 2. 진입 차수 배열 정의
  const indgree = Array.from({ length: N + 1 }, () => 0);
  // 3. 결과 배열 정의
  const result = Array.from({ length: N }, () => 0);
  for (let i = 0; i < M; i++) {
    const [a, b] = input[idx++].split(" ").map(Number);
    graph[a].push(b);
    indgree[b]++;
  }

  const queue = [];
  for (let i = 1; i <= N; i++) {
    // 4. 진입 차수가 0이면 큐에 과목과 시간 넣기
    if (indgree[i] === 0) queue.push([i, 1]);
  }
  const topology_sort = () => {
    while (queue.length) {
      // 5. 뽑기
      const [cur, time] = queue.shift();
      // 6. 결과 배열에 시간 할당
      result[cur - 1] = time;
        
      for (let next of graph[cur]) {
        indgree[next]--;
        if (indgree[next] === 0) {
          queue.push([next, time + 1]);
        }
      }
    }
  };
  topology_sort();
  console.log(result.join(" "));
};
solution(input);
