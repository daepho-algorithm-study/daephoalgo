const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, K) {
  const q = [[N, 0]];
  let head = 0;

  // 방문 했는지 여부 체크
  const visited = Array(100001).fill(false);

  if (N === K) return 0;

  while (q.length > head) {
    // 현재 위치, 시간을 꺼냄
    const [cur, time] = q[head++];

    // 다음 위치 후보군들
    const nexts = [[cur-1, time+1], [cur+1, time+1], [cur*2, time+1]];
    
    // 후보들 하나씩 보면서
    for (const [nxt, t] of nexts) {

      // 찾았으면 시간 반환
      if (nxt === K) return t;

      // 후보가 방문 안됐고 범위 내면 큐에 추가
      if (!visited[nxt] && nxt >= 0 && nxt <= 100000 ) {
        q.push([nxt, t]);
        visited[nxt] = true;
      }
    }
  }
}

const [N, K] = input[0].split(" ").map(Number);

console.log(solution(N, K));
