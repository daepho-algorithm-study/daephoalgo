const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/);
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(A, B, C) {
  // 숫자가 매우 크기 때문에 파라미터를 전부 bigInt로 바꿔줘야 함
  // BigInt는 BigInt 끼리만 연산 가능하기 때문에 연산하는 수도 모두 BigInt로 설정해줘야함
  const [bigA, bigB, bigC] = [BigInt(A), BigInt(B), BigInt(C)]
  const devide = (n) => {

    // 기저 조건
    if (n === 0n) return 1n;

    // 홀수일 경우
    if (n % 2n === 1n) {
      const n_1 = n - 1n; // n-1 구하기

      const half_1 = devide(n_1 / 2n) % bigC; // n-1(짝수)를 2로 나눈 재귀 연산 결과
      // 변수로 따로 빼주는 이유는 호출을 한번만 하기 위해서

      // 각 수에다 전부 C로 모듈러 연산(곱셈한 결과에서 모듈러는 곱하려는 연산자 따로 모듈러를 한 결과의 모듈러와 같음)
      return ((bigA % bigC) * (half_1 * half_1) % bigC) % bigC;

    // 짝수일 경우  
    } else {
      const half = devide(n / 2n) % bigC;
      return (half * half) % bigC;
    }
  };

  return devide(bigB).toString();
}

const lineOne = input.map((line) => line.split(" ").map(Number));
const [A, B, C] = lineOne[0];
console.log(solution(A, B, C));
