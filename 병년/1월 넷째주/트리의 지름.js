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

  for (let i = 0; i < N - 1; i++) {
    // 가중치 파싱
    const [u, v, w] = input[idx++].split(" ").map(Number);
    // 무향 그래프 에 가중치 추가
    graph[u].push({ to: v, cost: w });
    graph[v].push({ to: u, cost: w });
  }

  const bfs = (x) => {
    // 거리 배열
    let dist = Array.from({ length: N + 1 }, () => -1);
    dist[x] = 0;

    let head = 0;
    let queue = [x];
    while (head < queue.length) {
      let node = queue[head++];
      // 다음 좌표와 거리 뽑기
      for (const { to, cost } of graph[node]) {
        // 다음 좌표가 0이 아니라면 즉 이미 방문했다면 무시
        if (dist[to] !== -1) continue;
        // 다음 좌표에 현재 좌표의 거리에 비용 누적
        /**
         * 예를 들어 루트 노드가 1이고 1 -> 3 가는 비용이 2일 때
         * dist[3] = 0 + 2
         * 3에서 5 가는 비용이 11 일 때
         * dist[5] = 2 + 11
         * 5 에서 9 가는 비용이 15 일 때
         * dist[9] = 13 + 15
         */
        dist[to] = dist[node] + cost;
        queue.push(to);
      }
    }

    // 현재 노드 기준으로 가장 멀리있는 노드와 거기서 가장 멀리 있는 노드를 찾기 위해 변수 정의
    let nextNode = x;
    for (let i = 1; i <= N; i++) {
      // 가장 멀리 있는 노드 찾기
      if (dist[i] > dist[nextNode]) nextNode = i;
    }
    // 지름을 찾기 위한 거리도 반환하기 위해 정의
    let finalDist = dist[nextNode];
    // 다음에 가야할 노드와 최종 거리 반환
    /**
     * 이 코드에서 nextNode 는 다음에 루트 노드가 될 노드
     * finalDist 는 트리의 지름을 찾기 위한 두 번째 루트 노드에서 가장 거리가 먼 곳
     */
    return { nextNode, finalDist };
  };
  // A 는 1번(루트노드) 에서 가장 거리가 먼 곳
  const { nextNode: A } = bfs(1);
  // finalDist 는 루트 노드에서 가장 거리가 먼 곳에서 가장 거리가 먼 노드 까지의 거리
  // 즉, 가장 먼 곳에서 가장 먼곳 ==> 트리의 지름
  const { finalDist: result } = bfs(A);
  console.log(result);
};

solution(input);
