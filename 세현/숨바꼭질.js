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
  const visited = Array(100001).fill(false);

  if (N === K) return 0;

  while (q.length > head) {
    const [cur, time] = q[head++];
    const nexts = [[cur-1, time+1], [cur+1, time+1], [cur*2, time+1]];
    
    for (const [nxt, t] of nexts) {
      if (nxt === K) return t;
      if (!visited[nxt] && nxt >= 0 && nxt <= 100000 ) {
        q.push([nxt, t]);
        visited[nxt] = true;
      }
    }
  }
}

const [N, K] = input[0].split(" ").map(Number);

console.log(solution(N, K));
