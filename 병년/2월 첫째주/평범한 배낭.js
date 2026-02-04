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
  let idx = 0;
  const [N, K] = input[idx++].split(" ").map(Number);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }

  const dp = Array(K + 1).fill(0);
  // 배낭에 들은 물건 개수 만큼 반복문 돌리기
  for (let i = 0; i < N; i++) {
    // 무게와 값 뽑기
    let [w, v] = arr[i];

    // 뒤에서 부터 넣기 뒤에서 부터 넣는 이유는 이미 사용한 물건 재사용하지 않게 하기 위해서 예를 들어서
    /**
     * j = 2 w = 5 v = 10 라고 가정할 때 앞에서 부터 돌리면
     * dp[2] = dp[2], dp[0] + 10
     * dp[3] = dp[3], dp[1] + 10
     * dp[4] = dp[4], dp[2] + 10 <<< 여기서 이번에 만든 배낭을 한 번 더 사용하는 경우가 생기게 되어 원치않는 값이 나올 수 있음
     * 
     * 반대로 뒤에서 부터 돌리면
     * j = 5 w = 2 v = 10 
     * dp[5] = dp[5], dp[3] + 10
     * dp[4] = dp[4], dp[2] + 10
     * dp[3] = dp[3], dp[1] + 10
     * dp[2] = dp[2], dp[0] + 10 
     * 
     * 이런 식으로 이미 만든 배낭에 대한 값에 접근을 하지 않아 원하는 결과를 뽑을 수 있다.
     */
    for (let j = K; j >= w; j--) {
      dp[j] = Math.max(dp[j], dp[j - w] + v);
    }
  }
  console.log(dp[K]);
};
solution(input);
