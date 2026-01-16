const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M) {

  const visited = Array.from({length: N+1}, () => 0);
  const arr = Array.from({length: N}, (v, i) => i+1);
  const answer = [];

  // 순열
  const perm = (m, depth, result) => {

    // 원하는 갯수만큼 뽑았으면 정답에 추가
    if (depth === m) {
      answer.push(result.join(" "))
      return;
    }

    // 전체 수열에서 하나씩 수를 뽑기
    for (const a of arr) {

      // 그 수를 아직 쓰지 않았다면 부분수열에 추가
      if (!visited[a]) {
        visited[a] = 1;
        result.push(a)

        // 추가로 더 뽑기
        perm(m, depth+1, result);

        // 다음 수를 선택하기 전에 원래대로 되돌리기
        visited[a] = 0;
        result.pop();
      }
    }

  }
  perm(M, 0, []);
  return answer.join('\n');
}

console.log(solution(input[0][0], input[0][1]));
