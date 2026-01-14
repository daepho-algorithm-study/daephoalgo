const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, M) {
  const arr = Array.from({ length: N }, (v, i) => i + 1);
  const answer = [];

  // 중복 순열과 거의 같음
  const perm = (m, depth, result) => {

    if (depth === m) {
      answer.push(result.join(" "));
      return;
    }


    for (const a of arr) {
    
      // 한가지 더 추기해 줘야 할점
      if (result.length) {
        // 현재 요소가 부분순열의 마지막 요소보다 클 때만 선택해야 함
        if (a >= result[result.length - 1]) {
          result.push(a);

          perm(m, depth + 1, result);

          result.pop();
        }
      } else {
        // 첫번째 요소는 비교할 대상이 없으므로 바로 추가
        result.push(a);
        perm(m, depth + 1, result);
        result.pop();
      }
    }
  };
  perm(M, 0, []);
  return answer.join("\n");
}

console.log(solution(input[0][0], input[0][1]));
