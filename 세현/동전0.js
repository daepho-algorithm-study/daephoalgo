const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/);
//   .map((e) => Number(e));
// .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, K, coins) {
  let answer = 0;
  let idx = N-1;

  // 가장 큰 단위의 동전부터 탐색
  while(idx >= 0) {

    // 현재 동전
    const coin = coins[idx]

    // 현재 단위의 동전이 현재 금액보다 크면 패스
    if (K < coin) {
      idx--;
      continue;
    }

    // 현재 단위의 동전으로 몫연산해서 동전 개수에 더하기
    answer += ~~(K / coin)

    // 현재 금액 업데이트
    K = K % coin;

    idx--;
    
  }

  return answer;
}

const oneline = input[0].split(" ").map(Number);
const coins = input.slice(1).map((e) => Number(e));

console.log(solution(oneline[0], oneline[1], coins));
