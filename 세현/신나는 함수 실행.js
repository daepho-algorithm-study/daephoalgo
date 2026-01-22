const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input.length-1 // 마지막 줄은 -1, -1, -1 이므로 고려하지 않음

  //메모이제이션 배열 (변수가 3개이므로 3차원 배열)
  const depth = 21, rows = 21, cols = 21; // 식 중 하나가 a, b, c 모두 20을 넘어갈 때는 20으로 간주한다고 되어있으므로 배열 길이는 0~20까지만 해주면 됨
  const memo = Array.from({length: depth}, () => 
        Array.from({length: rows}, () => 
            Array.from({length: cols}, () => 0) // 모두 0으로 초기화
        )
    );

  // 초기값 설정 
  memo[0][0][0] = 1;
  
  // if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns: 1
  const w = (a, b, c) => {
    // 0 미만의 변수가 하나라도 있으면 결과를 1로 간주
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    
    // 20 초과한 변수가 하나라도 있으면 모든 변수를 20으로 간주
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    // 핵심 구문(위치 중요)
    // 변수에 해당하는 결과를 이미 기록하고 있을 때 그 값을 가져오고 바로 빠져나감
    if (memo[a][b][c] !== 0) {
        return memo[a][b][c];
    }

    // 기록된 결과가 없다면? 기록을 해야 함
    // 재귀로 주어진 식에 맞춰서 memo 배열에 기록하기
    if (a < b && b < c) {
        memo[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    } else {
        memo[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }

    // 0 ~ 20 사이의 변수들로 구성되었을 때 위의 식은 memo 배열에 기록만 함
    // 따라서 기록했던 memo[a][b][c]의 결과값을 반환해 주지 않는다면 undefined를 반환함
    // 반드시 기록했던 값을 반환해 줘야 함
    return memo[a][b][c]
  }

  // 결과 출력(여러 케이스 모두)
  for (let i = 0; i < N; i++) {
    const [a, b, c] = input[i];
    console.log(`w(${a}, ${b}, ${c}) = ${w(a, b, c)}`)
  }

}

solution(input);
