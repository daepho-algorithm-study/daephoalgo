const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, V, edges) {
  const answer = [];

  // 인접 리스트 생성 (정점 번호: 1 ~ N)
  const adjL = Array.from({ length: N + 1 }, () => []);
  for (const [a, b] of edges) {
    adjL[a].push(b);
    adjL[b].push(a);
  }

  // 번호가 작은 정점부터 방문하기 위해 정렬
  for (let i = 1; i <= N; i++) {
    adjL[i].sort((a, b) => a - b);
  }

  // 스택을 이용한 DFS
  const dfs = (start, N) => {
    const visited = Array.from({ length: N + 1 }, () => false);
    visited[start] = true;

    const stack = [];        // 되돌아갈 경로 저장
    const result = [start]; // 방문 순서 저장
    let v = start;

    while (true) {
      let moved = false;

      // 현재 정점에서 갈 수 있는 정점 탐색
      for (const w of adjL[v]) {
        if (!visited[w]) {
          visited[w] = true;
          stack.push(v);   // 현재 위치 저장
          result.push(w);
          v = w;           // 다음 정점으로 이동
          moved = true;
          break;
        }
      }

      // 더 이상 갈 곳이 없으면 이전 정점으로 백트래킹
      if (!moved) {
        if (stack.length > 0) {
          v = stack.pop();
        } else {
          break; // 스택도 비면 종료
        }
      }
    }
    return result;
  };

  // 큐를 이용한 BFS
  const bfs = (start, N) => {
    const q = [start];
    const visited = Array.from({ length: N + 1 }, () => false);
    const result = [];

    while (q.length) {
      const v = q.shift();

      if (visited[v]) continue;
      visited[v] = true;
      result.push(v);

      // 인접한 정점들을 큐에 추가
      for (const next of adjL[v]) {
        if (!visited[next]) {
          q.push(next);
        }
      }
    }
    return result;
  };

  answer.push(dfs(V, N).join(" "));
  answer.push(bfs(V, N).join(" "));

  return answer.join('\n');
}

console.log(solution(input[0][0], input[0][1], input[0][2], input.slice(1)));
