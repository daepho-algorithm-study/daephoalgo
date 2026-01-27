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
  const arr = input[0].split(" ").map(Number);
  const N = arr.shift();
  // 계산의 편의성을 위해 100을 나눠줌 25 => 0.25
  const mappedArr = arr.map((value) => value / 100);
  // 중간값 기준으로 갈 수 있는 최대 범위를 지정하기 위해 N * 2 + 1을 해줌 ex) N = 2 라면 상하좌우로 최대 2칸 씩 갈 수 있기 때문임
  const size = N * 2 + 1;
  const visited = Array.from({ length: size }, () => Array(size).fill(false));

  // 델타 배열
  const dx = [0, 0, 1, -1];
  const dy = [1, -1, 0, 0];

  let answer = 0;

  // dfs 실행
  const dfs = (x, y, depth, percentage) => {
    // 방문 체크
    visited[x][y] = true;
    // 깊이가 N 만큼 내려가면 최종 퍼센테이지 합산
    if (depth === N) {
      answer += percentage;
      return;
    }
    // 델타 탐색
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];

      // 아직 방문하지 않았으면 방문 체크 후 dfs 탐색
      if (!visited[nx][ny]) {
        visited[nx][ny] = true;
        // 깊이와 이동확률 누적 예를 들어, 왼쪽으로 가는 확률이 25라면 0.25 곱해주고
        // 다음 값에서 또 왼쪽으로 간다면 0.25 * 0.25 해주기
        dfs(nx, ny, depth + 1, percentage * mappedArr[k]);
        // 백트래킹
        visited[nx][ny] = false;
      }
    }
  };

  dfs(N, N, 0, 1);
  console.log(answer);
};

solution(input);
