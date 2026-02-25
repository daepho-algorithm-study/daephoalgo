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
  const [N, K] = input[idx++].split(" ").map(Number);
  // 1. 진입 차수 정의
  const indgree = Array.from({ length: N + 1 }, () => 0);
  const graph = Array.from({ length: N + 1 }, () => []);

  for (let i = 1; i <= K; i++) {
    const [size, ...singers] = input[idx++].split(" ").map(Number);
    for (let j = 0; j < size; j++) {
      for (let k = j + 1; k < size; k++) {
        const high = singers[j];
        const low = singers[k];

        graph[high].push(low);
        indgree[low]++;
      }
    }
  }

  // 2. queue 선언
  const queue = [];
  const results = [];
  for (let i = 1; i <= N; i++) {
    if (indgree[i] === 0) {
      queue.push(i);
    }
  }

  // 3. 위상 정렬 수행
  const topology_sort = () => {
    while (queue.length) {
      const cur = queue.shift();
      if (indgree[cur] === 0) results.push(cur);
      for (let next of graph[cur]) {
        indgree[next]--;
        if (indgree[next] === 0) {
          queue.push(next);
        }
      }
    }
  };

  topology_sort();
  // 4. 사이클이 존재할 경우 즉, 순서를 정할 수 없을 경우
  if (results.length !== N) {
    console.log(0);
    return;
  }
  for (let result of results) {
    console.log(result);
  }
};
solution(input);
