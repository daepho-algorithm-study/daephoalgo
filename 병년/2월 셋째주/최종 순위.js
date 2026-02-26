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
  const T = input[idx++];
  for (let tc = 0; tc < T; tc++) {
    const N = Number(input[idx++]);
    const lastYear = input[idx++].split(" ").map(Number);
    const M = Number(input[idx++]);
    const graph = Array.from({ length: N + 1 }, () => []);
    const changes = [];
    // 1. 바뀐 순서 입력 받기
    for (let i = 0; i < M; i++) {
      const [a, b] = input[idx++].split(" ").map(Number);
      changes.push([a, b]);
    }
    // 2. 진입 차수 배열 설정
    const indegree = Array(N + 1).fill(0);
    // 3. 작년 순서 기준으로 그래프 만들기
    for (let i = 0; i < N; i++) {
      for (let j = i + 1; j < N; j++) {
        const higher = lastYear[i];
        const lower = lastYear[j];

        graph[higher].push(lower);
        indegree[lower]++;
      }
    }
    // 4. 방향 뒤집기
    for (let change of changes) {
      // 방향을 바꿀 노드 뽑아오고
      let [a, b] = change;
      // a의 앞에 b가 존재하면
      if (graph[a].includes(b)) {
        // b를 빼주고
        graph[a] = graph[a].filter((v) => v !== b);
        // b의 진입차수를 줄여줌 a 에서 b가 빠졌기 때문에 나보다 앞에 있는 팀의 수를 하나만큼 줄여주는 것
        indegree[b]--;
        // b에 a를 넣어줌
        graph[b].push(a);
        // a 가 b의 앞으로 이동했기 때문에 a 의 나보다 앞에 있는 팀의 수를 늘려줌
        indegree[a]++;
        // 반대로 b 앞에 a가 존재하면
      } else {
        // a를 빼주고
        graph[b] = graph[b].filter((v) => v !== a);
        // a의 진입 차수를 줄여줌 b 에서 a가 빠졌기 때문에 나보다 앞에 있는 팀의 수를 하나만큼 줄여주는 것
        indegree[a]--;
        // a 에 b를 넣어줌
        graph[a].push(b);
        // b가 a의 앞으로 이동했기 때문에 b의 나보다 앞에 있는 팀의 수를 늘려줌
        indegree[b]++;
      }
    }

    // 5. 위상 정렬 수행
    const result = [];
    const queue = [];
    // 인접 차수가 0인 경우 큐에 넣기
    for (let i = 1; i <= N; i++) {
      if (indegree[i] === 0) queue.push(i);
    }

    while (queue.length) {
      /**
       * 만약 큐에 들어간 노드가 2개 이상이라면 진입 차수가 0인 노드가 2개 이상이기 때문에
       * 우열을 가릴 수 없으므로 ? 출력하고 break
       * */
      if (queue.length > 1) {
        console.log("?");
        break;
      }
      // 진입 차수가 0인 노드 뽑아서 result에 저장
      const next = queue.shift();
      result.push(next);
      // 다음 노드 탐색하면서 진입 차수 줄여주기
      for (let adj of graph[next]) {
        indegree[adj]--;
        // 진입차수가 0이 되면 큐에 넣기
        if (indegree[adj] === 0) {
          queue.push(adj);
        }
      }
    }

    console.log(result.length !== N ? "IMPOSSIBLE" : result.join(" "));
  }
};

solution(input);
