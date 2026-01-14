const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, abilities) {
  const teamSize = N / 2;   // 각 팀 총원
  let answer = Infinity;

  // A팀으로 뽑혔는지 여부
  const visited = Array.from({ length: N }, () => false);

  const dfs = (depth, idx) => {
    if (depth === teamSize) {
      let Apower = 0,   //A 팀 능력치
        Bpower = 0;     //B 팀 능력치
      const teamA = [],
        teamB = [];

      for (let i = 0; i < N; i++) {
        if (visited[i]) {
          teamA.push(i);
        } else {
          teamB.push(i);
        }
      }

      // 각 팀의 능력치 합산
      for (let i = 0; i < teamSize; i++) {
        for (let j = 0; j < teamSize; j++) {
          Apower += abilities[teamA[i]][teamA[j]];
          Bpower += abilities[teamB[i]][teamB[j]];
        }
      }

      // 팀 능력치 차이 계산
      const diff = Math.abs(Apower - Bpower);
      // 최솟값 갱신
      if (diff < answer) answer = diff;
      return;
    }

    // 조합
    for (let i = idx; i < N; i++) {

      // 뽑히지 않은 경우만 진행
      if (!visited[i]) {
        visited[i] = true;

        // i번째까지는 검토된 것이므로 다음 단계에선 i+1 이후만 봐야 함
        dfs(depth + 1, i + 1);
        visited[i] = false;
      }
    }
  };

  dfs(0, 0);

  return answer;
}

console.log(solution(input[0][0], input.slice(1)));
