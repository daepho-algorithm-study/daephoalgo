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
  // 입력값 파싱을 위한 idx 값
  let idx = 0;
  // 노드와 간선 의 개수
  const [N, M] = input[idx++].split(" ").map(Number);
  // 거리 배열 무한대로 초기화
  const dist = Array(N + 1).fill(Infinity);
  const graph = [];
  // 그래프에 노드, 간선, 비용 삽입
  for (let i = 0; i < M; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    graph.push([a, b, c]);
  }
  // 벨만 포드 알고리즘 수행
  const bellman_ford = (start) => {
    // 시작점 0으로 초기화
    dist[start] = 0;
    // 모든 간선 검사
    for (let i = 0; i < N - 1; i++) {
      for (let j = 0; j < M; j++) {
        // 정보 뽑기
        const [node, next, cost] = graph[j];
        // 만약 현재 거리가 무한대가 아니고 다음 거리가 현재 거리에서 비용을 추가한것 보다 크다면
        if (dist[node] !== Infinity && dist[next] > dist[node] + cost) {
          // 다음 거리에 현재 거리에 비용을 합친 값 할당
          dist[next] = dist[node] + cost;
        }
      }
    }
    /** 음수 사이클 검사
     * 벨만 포드 알고리즘을 통해서 최소값으로 갱신을 마쳤음에도 불구하고
     * 아직도 다음에 갈 값이 현재 값에 비용보다 더한 값보다 더 크다면
     * 음의 사이클 이기 때문에 true 반환
     **/
    for (let j = 0; j < M; j++) {
      const [node, next, cost] = graph[j];

      if (dist[node] !== Infinity && dist[next] > dist[node] + cost) {
        return true;
      }
    }

    return false;
  };
  let flag = bellman_ford(1);

  if (flag) {
    console.log(-1);
  } else {
    for (let i = 2; i <= N; i++) {
      if (dist[i] === Infinity) {
        console.log(-1);
      } else {
        console.log(dist[i]);
      }
    }
  }
};
solution(input);
