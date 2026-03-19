const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;

  // N: 노드 개수, M: 시작 노드
  const [N, M] = input[idx++].split(" ").map(Number);

  // 초기 비용 행렬 (직접 이동 비용)
  const arr = [];
  for (let i = 0; i < N; i++) {
    const row = input[idx++].split(" ").map(Number);
    arr.push(row);
  }

  /**
   *  플로이드 워셜
   * 모든 i → j 최단 비용으로 갱신
   *
   * 이후 DFS에서 "직접 간선"이 아니라
   * "최소 비용 경로"를 사용하게 됨
   */
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }

  let answer = Infinity;

  // 방문 여부 체크 (각 노드는 한 번만 방문)
  const visited = Array.from({ length: N }, () => false);

  // 시작 노드 방문 처리
  visited[M] = true;

  /**
   * DFS (백트래킹)
   *
   * idx: 현재 위치
   * cnt: 방문한 노드 개수
   * sum: 지금까지 누적 비용
   */
  const dfs = (idx, cnt, sum) => {
    // 가지치기: 이미 답보다 크면 더 볼 필요 없음
    if (sum >= answer) return;

    // 모든 노드 방문 완료
    if (cnt === N) {
      answer = Math.min(answer, sum);
      return;
    }

    // 다음 방문할 노드 선택
    for (let i = 0; i < N; i++) {
      if (!visited[i]) {
        visited[i] = true;

        // 현재 위치 → i 로 이동 (최단 비용 사용)
        dfs(i, cnt + 1, sum + arr[idx][i]);

        // 백트래킹
        visited[i] = false;
      }
    }
  };

  // 시작점 M부터 탐색 시작
  dfs(M, 1, 0);

  console.log(answer);
};

solution(input);
