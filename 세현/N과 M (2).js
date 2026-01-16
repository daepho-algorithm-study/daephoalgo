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

  // 조합
  const comb = (m, carr, result) => {

    // 원하는 갯수만큼 뽑았으면 정답에 추가
    if (m === 0) {
      answer.push(result.join(" "))
      return;
    }

    
    for (let i = 0; i < carr.length; i++) {

        result.push(carr[i]);
        
        // i 이전의 수들은 이미 검토가 끝났음(필요없음)
        const nextarr = carr.slice(i+1);

        // 다음 수 뽑기
        comb(m-1, nextarr, result);

        // 복구 코드
        result.pop();
      
    }

  }
  comb(M, arr, []);
  return answer.join('\n');
}

console.log(solution(input[0][0], input[0][1]));
