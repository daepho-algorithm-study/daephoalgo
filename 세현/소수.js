const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  const [M, N] = input;

  // M ~ N 범위 (N-M+1 크기) -> 소수인지 판단하는 배열 생성
  // offset으로 맨 처음 방 index 0을 M으로 맞춰줄거임
  const isPrime = Array.from({ length: N - M + 1 }, () => true);

  // 만약 M이 1이면 1부터 배열이 시작되는데
  // 1은 소수가 아닌 놈이기 때문에 제외시켜 주어야함 (합성수도 아님)
  // N-M+1 크기라고 해서 isPrime[0] 이 0인줄 착각했었는데 0이 아니라 1임(중요)
  if (M === 1) isPrime[0] = false;

  // 제곱근 방식과 에라토스테네스의 채 방식을 합쳐서 사용해봄
  for (let i = 2; i * i <= N; i++) {
    // N의 제곱근 까지만 비교

    // start: M 이상인 i의 배수를 찾음
    let start = Math.max(i * i, Math.ceil(M / i) * i);
    // 예시로 M = 10, i = 3이면
    // M/i = 10/3 = 3.33 ---> ceil(올림) ---> 4
    // 4*3 = 12 로 10 이상인 3의 배수 중 가장 작은 수 12를 찾을 수 있음

    for (let j = start; j <= N; j += i) {
      //i의 배수들을 다 소수가 아님 (채로 걸러내는 작업)
      isPrime[j - M] = false; //M으로 offset 맞춰줘야함
    }
  }
  let answer = [0, 0];
  let isMin = false; // 가장 작은 소수인지 판별
  for (let i = 0; i < isPrime.length; i++) {
    if (isPrime[i]) {
      answer[0] += i + M;
      if (!isMin) {
        answer[1] = i + M;
        isMin = true;
      }
    }
  }

  return answer[0] ? String(answer[0]) + "\n" + String(answer[1]) : -1;
}

console.log(solution(input));
