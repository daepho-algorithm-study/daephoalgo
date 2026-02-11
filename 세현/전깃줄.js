const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, poles) {

  // A전봇대 기준으로 정렬
  // 한쪽을 고정해야 교차 판단이 가능함
  poles.sort((a, b) => a[0] - b[0]);

  // i번째 전깃줄까지 봤을 때
  // i에서 끝나는 LIS 길이 저장
  const dp = Array.from({length: N}, () => 1);

  // LIS 구하는 부분
  // B전봇대 기준 증가하는 부분수열 찾는 것과 동일
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {

      // B값이 증가하면 교차하지 않음
      if (poles[i][1] > poles[j][1]) {

        // j를 거쳐서 오는 경우 vs 기존 값 비교
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  // 전체 개수 - LIS 길이
  // 제거해야 할 최소 전깃줄 개수
  return N - Math.max(...dp);
}

console.log(solution(input[0][0], input.slice(1)));
