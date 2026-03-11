const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  /**
   * 먼저, 오민식이가 교통수단을 이용하면 비용을 지불하고 도착지점에 도착하면
   * 비용을 다시 얻게 되는 경우가 있음 이용한 비용보다 번 비용이 더 많다면
   * 음수의 비용을 가지게 됨 결국 벨만-포드 알고리즘으로 음의 사이클을 찾아야함
   * 또한 해당 도시가 음의 사이클에 있다고 끝이 아님 해당 도시에서 마지막 도시로
   * 갈 수 있는 지 파악을 해야 하므로 bfs 탐색을 또 진행 해줌
   * 결국 음의 사이클에 포함되는 모든 도시를 queue에 넣고
   * 도착 도시에 갈 수 있으면 Gee
   * 아니라면 도착 도시의 비용 출력
   * 도착 도시를 방문조차 할 수 없다면 gg 출력
   */
  let idx = 0;
  let [N, start, end, M] = input[idx++].split(" ").map(Number);
  const edge = [];
  const INF = Infinity;
  const dist = Array(N).fill(INF);
  const visited = Array(N).fill(false);
  const queue = [];

  // 간선 정보 저장
  for (let i = 0; i < M; i++) {
    const [S, E, cost] = input[idx++].split(" ").map(Number);
    edge.push([S, E, cost]);
  }

  // 비용 정보 저장
  const money = input[idx++].split(" ").map(Number);

  // 벨만 포드 알고리즘 시작
  const bellman_ford = (start) => {
    // 시작 지점에서 비용 지불
    dist[start] = -money[start];
    // N - 1 만큼 반복
    for (let i = 0; i < N - 1; i++) {
      for (const [node, next, cost] of edge) {
        // 현재 노드 값, 다음 좌표, 비용 뽑기
        if (
          // 지금 노드가 무한대가 아니면서 다음 노드의 값이 현재 노드의 비용 더한 값에서
          // 내야할 비용을 뺀 값보다 더 크다면
          dist[node] !== INF &&
          dist[next] > dist[node] + cost - money[next]
        ) {
          // 갱신
          dist[next] = dist[node] + cost - money[next];
        }
      }
    }
    // 교통수단의 개수 만큼 다시 반복해서 음수 사이클 찾아내기
    for (const [node, next, cost] of edge) {
      // 아직도 다음 노드의 값이 현재 노드의 비용 더한 값에서 내야할 비용을 뺀 값보다 크다면
      if (dist[node] !== INF && dist[next] > dist[node] + cost - money[next]) {
        // 음수 사이클이므로 현재 노드를 queue에 넣고 방문 처리
        queue.push(next);
        visited[next] = true;
      }
    }
  };
  // bfs 함수
  const bfs = () => {
    let head = 0;
    while (queue.length > head) {
      // 음의 사이클에 포함된 첫 번째 도시 뽑기
      let now = queue[head++];
      // 도착도시에 방문할 수 있다면 음수 사이클 내부에 도착도시가 있는 것이므로 true
      if (now === end) {
        return true;
      }
      // 노선 만큼 반복 돌려서 cur, next 뽑기
      for (const [cur, next, _] of edge) {
        // 현재 값이 음에 사이클에 포함되고 아직 다음 도시를 가지 않았다면
        if (now === cur) {
          if (!visited[next]) {
            // 큐에 넣고 방문 처리
            queue.push(next);
            visited[next] = true;
          }
        }
      }
    }

    // 아니라면 false
    return false;
  };
  // 시작값으로 벨만포드 알고리즘 수행
  bellman_ford(start);
  // 그 후 bfs 돌려서 flag 값 뽑기
  let flag = bfs();
  // 도착도시에 방문한 적이 없으면 gg
  if (dist[end] === INF) {
    console.log("gg");
    // 도착했으나 음수사이클이면 Gee 아니면 비용 출력
  } else {
    console.log(flag ? "Gee" : -dist[end]);
  }
};
solution(input);
