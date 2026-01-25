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
  const [N, M] = input[idx++].split(" ").map(Number);

  // 정방향 그래프
  const graph = Array.from({ length: N + 1 }, () => []);
  // 역방향 그래프
  const revers = Array.from({ length: N + 1 }, () => []);

  for (let i = 0; i < M; i++) {
    // 그래프 채우기
    const [a, b] = input[idx++].split(" ").map(Number);
    graph[a].push(b);
    revers[b].push(a);
  }

  // 결과 값
  let answer = 0;

  //   const dfs = (x, graph, visited) => {
  //     // 다음 경로 체크
  //     for (let nx of graph[x]) {
  //       // 아직 방문 안한 노드면
  //       if (!visited[nx]) {
  //         // 방문 체크 후 더 들어가기
  //         visited[nx] = true;
  //         dfs(nx, graph, visited);
  //       }
  //     }
  //   };

  const bfs = (x, graph, visited) => {
    let head = 0;
    let queue = [x];
    while (head < queue.length) {
      let next = queue[head++];
      for (let nx of graph[next]) {
        if (!visited[nx]) {
          visited[nx] = true;
          queue.push(nx);
        }
      }
    }
  };

  for (let i = 1; i <= N; i++) {
    // 노드 별로 방문체크를 따로 진행해야 하므로 for 문 내부에 visited 배열 생성
    let visited1 = Array(N + 1).fill(false);
    let visited2 = Array(N + 1).fill(false);

    // 나와 키를 잴 수 있는 사람 카운트
    let cnt = 0;

    // 현재 노드 방문 체크
    visited1[i] = true;
    visited2[i] = true;

    // 정방향, 역방향에 dfs 탐색
    bfs(i, graph, visited1);
    bfs(i, revers, visited2);

    // 방문 체크를 통해 나와 키 비교가 가능한 사람 존재하면 cnt 추가
    for (let j = 1; j <= N; j++) {
      if (visited1[j] || visited2[j]) cnt++;
    }

    // 내 키가 몇 번째인 지 알기 위해서는 모든 사람과 비교가 가능해야 함
    if (cnt === N) answer++;
  }

  console.log(answer);
};

solution(input);
