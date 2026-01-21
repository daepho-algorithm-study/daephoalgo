const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");
let idx = 0;
const solution = (input) => {
  const [N, M] = input[idx++].split(" ").map(Number);
  const arr = Array.from({ length: N }, () =>
    input[idx++].split(" ").map(Number)
  );

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  const dp = Array.from({ length: N }, () => Array(M).fill(-1));
  let answer = 0;
  const dfs = (x, y) => {
    // 도착하면 1 반환
    if (x === N - 1 && y === M - 1) {
      return 1;
    }

    // 이미 계산한 적이 있으면 재사용
    if (dp[x][y] !== -1) return dp[x][y];

    // 초기화
    dp[x][y] = 0;

    // 델타 탐색
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[x][y] > arr[nx][ny]) {
          // 현재 좌표에 마지막까지 갔을 때의 경우의 수 누적
          dp[x][y] += dfs(nx, ny);
        }
      }
    }
    // 마지막에 현재 좌표값에서 마지막 좌표로 갈 수 있는 경로 반환
    return dp[x][y];
  };
  answer = dfs(0, 0);
    console.log(answer);
};

solution(input);
