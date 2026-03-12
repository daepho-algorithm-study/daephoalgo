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
  /**
   * 이 문제도 오민식의 고민과 동일하게 음의 사이클 체크 하고 bfs 를 통해서 도착 도시를 갈 수 있는지
   * 체크하는 문제인데 여기서 다른 점은 오민식이는 그저 조건에 맞게 출력하면 끝이었지만 얘는 경로를
   * 복원해줘야 함 그래서 parent 배열을 추가함
   */
  let idx = 0;
  // N, M 파싱
  const [N, M] = input[idx++].split(" ").map(Number);
  // 노드, 비용 저장할 배열
  const edge = [];
  for (let _ = 0; _ < M; _++) {
    let [cur, next, cost] = input[idx++].split(" ").map(Number);
    edge.push([cur, next, -cost]);
  }
  // 거리 저장용 배열
  const dist = Array(N + 1).fill(Infinity);
  // bfs 탐색 용 큐
  const queue = [];
  // 방문 체크 배열
  const visited = Array(N + 1).fill(false);
  // 경로 복원용 배열
  const parent = Array(N + 1).fill(-1);
  // 벨만 포드 알고리즘 수행
  const bellman_ford = (start) => {
    // 초기값 0으로 설정
    dist[start] = 0;
    // N - 1 까지 반복해서 노드 체크
    for (let i = 0; i < N - 1; i++) {
      for ([cur, next, cost] of edge) {
        // 현재 노드값 뽑아서 방문했으며, 다음 좌표의 값이 현재 좌표의 비용을 더한 값보다 크다면
        if (dist[cur] !== Infinity && dist[next] > dist[cur] + cost) {
          // 다음 좌표에 할당
          dist[next] = dist[cur] + cost;
          // 다음 좌표의 부모로 현재 좌표 넣기
          parent[next] = cur;
        }
      }
    }
    // 음수 사이클 체크
    for ([cur, next, cost] of edge) {
      // 아직도 방문한 노드에서 다음 값이 현재 값에 비용을 더한 값보다 크다면
      if (dist[cur] !== Infinity && dist[next] > dist[cur] + cost) {
        // 큐에 넣고 방문 체크
        queue.push(next);
        visited[next] = true;
      }
    }
  };
  // bfs 수행
  const bfs = () => {
    let head = 0;
    while (queue.length > head) {
      // 음의 사이클에 포함된 첫 번째 값 뽑기
      const now = queue[head++];
      // 그 값이 도착 지점이라면 바로 음수 사이클 내부에 도착 지점이 속하므로 반환
      if (now === N) {
        return true;
      }
      // 노드에서 cur, next 뽑기
      for ([cur, next, _] of edge) {
        // 현재 값과 음의 사이클에 포함된 값이 동일할 때
        if (cur === now) {
          // 아직 방문 안했으면
          if (!visited[next]) {
            // 방문 체크 후 큐에 넣기
            visited[next] = true;
            queue.push(next);
          }
        }
      }
    }
    // 성공적으로 bfs 탐색이 끝나면 false 반환
    return false;
  };
  // 시작점 1로 벨만 포드 알고리즘 수행
  bellman_ford(1);
  // flag 값 뽑기
  let flag = bfs();
  // true 라면 도착 도시가 음에 사이클에 속하므로 -1 출력
  if (flag) {
    console.log(-1);
    // 아니라면 경로 복원
  } else {
    // 출력 용 배열 생성
    const path = [];
    // 현재 값 N 으로 설정 그 이유는 마지막 도착 지점이 N 이기 때문
    let cur = N;
    // cur 이 -1 아닐 때까지 반복 즉, 부모가 없을 때 까지
    while (cur !== -1) {
      // 출력 용 배열에 현재 값 넣기
      path.push(cur);
      // 현재 값의 부모값으로 갱신
      cur = parent[cur];
    }
    // 반대로 뒤집어서 출력하기
    console.log(path.reverse().join(" "));
  }
};
solution(input);
