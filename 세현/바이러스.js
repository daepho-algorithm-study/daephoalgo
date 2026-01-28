const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, networks) {
  // 컴퓨터 간 연결 관계를 저장할 인접 리스트
  const computers = Array.from({ length: N + 1 }, () => []);
  
  // 감염 여부 체크 배열
  const infected = Array.from({ length: N + 1 }, () => 0);

  // 양방향 그래프
  for (const [a, b] of networks) {
    computers[a].push(b);
    computers[b].push(a);
  }

  // 1번 컴퓨터부터 BFS 시작
  const q = [1];
  infected[1] = 1;

  while (q.length) {
    const next = q.shift();

    // 연결된 컴퓨터 탐색
    for (const com of computers[next]) {
      if (infected[com]) continue;

      infected[com] = 1;
      q.push(com);
    }
  }

  // 감염된 컴퓨터 수에서 1번 컴퓨터 제외
  const answer = infected.reduce((a, b) => a + b, 0) - 1;

  return answer;
}

console.log(solution(input[0][0], input.slice(2)));
