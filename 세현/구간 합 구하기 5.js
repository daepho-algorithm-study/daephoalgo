const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M, table, Qs) {
  let answer = "";

  // 2D 누적합 배열
  const S = Array.from({ length: N + 1 }, () => Array.from({ length: N + 1 }, () => 0));
  
  // 누적합 배열 계산
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {

      // 끝점에서 시작점의 누적값 빼주고 마지막에 중복으로 차감한 왼쪽 위 더해주기
      S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + table[i - 1][j - 1];
    }
  }
  
  // 각 쿼리 (x1,y1)~(x2,y2) 범위 합 계산
  for (const Q of Qs) {
    const [x1, y1, x2, y2] = Q;
    answer += (S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]) + "\n"
  }

  return answer.trim();
}

console.log(solution(input[0][0], input[0][1], input.slice(1, input[0][0] + 1), input.slice(input[0][0] + 1)));
