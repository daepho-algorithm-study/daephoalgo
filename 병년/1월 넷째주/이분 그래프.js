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

  const T = Number(input[idx++]); // 테스트 케이스 수

  for (let tc = 0; tc < T; tc++) {
    const [N, M] = input[idx++].split(" ").map(Number);

    const visited = Array.from({ length: N + 1 }, () => 0);
    const graph = Array.from({ length: N + 1 }, () => []);
    let flag = false;

    for (let i = 0; i < M; i++) {
      const [a, b] = input[idx++].split(" ").map(Number);
      graph[a].push(b);
      graph[b].push(a);
    }

    // const bfs = (node) => {
    //   let head = 0;
    //   let queue = [node];
    //   visited[node] = 1;
    //   while (head < queue.length) {
    //     let x = queue[head++];

    //     for (let nx of graph[x]) {
    //       if (visited[nx] === 0) {
    //         visited[nx] = visited[x] * -1;
    //         queue.push(nx);
    //       } else {
    //         if (visited[x] === visited[nx]) {
    //           return false;
    //         }
    //       }
    //     }
    //   }
    //   return true;
    // };

    const dfs = (node) => {
      for (let nx of graph[node]) {
        // 만약 아직 색칠이 안되어 있으면
        if (visited[nx] === 0) {
          // 인접 노드 반대 색상 색칠
          visited[nx] = visited[node] === "시" ? "발" : "시";
          // 재귀 호출 계속 높아지는 depth 기저 조건으로 false 한번 나오면 계속 false로 탈출
          if (!dfs(nx)) return false;
        } else {
          // 이미 색칠되어 있는데 현재 색상과 동일하다면
          if (visited[nx] === visited[node]) {
            // 도망쳐~~
            return false;
          }
        }
      }
      return true;
    };

    for (let i = 1; i < graph.length + 1; i++) {
      if (visited[i] === 0) {
        // 시작 색깔 시로 설정
        visited[i] = "시";
        // dfs 탐색 결과
        flag = dfs(i);
        if (!flag) break;
      }
    }
    console.log(flag ? "YES" : "NO");
  }
};
solution(input);
