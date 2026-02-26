const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, A) {
  let answer = 0;

  const S = Array.from({ length: N + 1 }, () => 0); // 누적합 배열
  const namuji = Array.from({ length: M }, () => 0); // 나머지별 등장 횟수

  // 공집합(S[0] = 0)의 나머지 0 처리
  namuji[0] = 1;

  for (let i = 1; i <= N; i++) {
    S[i] = S[i - 1] + A[i - 1]; // 누적합 계산
    const nam = S[i] % M;
    namuji[nam]++; // 해당 나머지 카운트 증가
  }

  // 같은 나머지를 가진 쌍의 수 → (S[j] - S[i]) % M == 0인 부분합 개수
  for (let i = 0; i < M; i++) {
    answer += (namuji[i] * (namuji[i] - 1)) / 2; // nC2 조합
  }

  return answer;
}

console.log(solution(input[0][0], input[0][1], input[1]));
