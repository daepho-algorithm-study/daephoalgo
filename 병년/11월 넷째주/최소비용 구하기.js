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
  let N = Number(input[idx++]);
  let M = Number(input[idx++]);

  const graph = {};
  for (let i = 0; i <= N; i++) {
    graph[i] = [];
  }

  for (let i = 0; i < M; i++) {
    const [a, b, c] = input[idx++].split(" ").map(Number);
    graph[a].push({ to: b, cost: c });
  }

  const [start, end] = input[idx++].split(" ").map(Number);
  // 거리 정보를 담은 배열
  const dist = Array(N + 1).fill(Infinity);
  // 방문 체크용 배열
  const visited = Array(N + 1).fill(false);
  let answer = 0;
  // 시작 지점 초기화
  dist[start] = 0;

  const dijkstra = () => {
    // 결과 값
    let result = 0;
    for (let i = 0; i < N; i++) {
      // 현재값
      let now = -1;
      /**
       * 다익스트라 문제를 풀기위한 최소 값 설정
       * 그래프의 반복을 돌리면서 다음 좌표 값에 방문하지 않았고
       * 최소값 보다 다음 좌표의 거리가 작다면 갱신
       * */

      let min = Infinity;

      for (let j = 1; j <= N; j++) {
        if (!visited[j] && dist[j] < min) {
          min = dist[j];
          now = j;
        }
      }
      // 만약 현재 값이 변하지 않았다면(최소값을 찾지 못했다면) 종료
      if (now === -1) break;
      // 방문 체크
      visited[now] = true;
      // 다음 좌표 값 검사
      for (const next of graph[now]) {
        // 비용 계산 현재 좌표에서의 거리와 다음 좌표까지의 비용을 더해줌
        const newCost = dist[now] + next.cost;
        // 그 후 새로운 비용 값이 다음 좌표의 거리보다 작다면
        if (newCost < dist[next.to]) {
          // 갱신
          dist[next.to] = newCost;
        }
      }
    }
    // 마지막 좌표값 반환
    result = dist[end];
    return result;
  };
  answer = dijkstra();
  console.log(answer);
};
solution(input);
