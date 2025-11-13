const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = Number(input[0]);

  //각 수마다 분해합에 해당하는지 모두 확인해보면서 넘어감
  for (let i = N-(9*input[0].split('').length); i < N; i++) {
    // 시작 수를 N-(자릿수개수*9) 로 놓아도 됨
    // 왜냐하면 각 자릿수는 아무리 커 봤자 9 이하 이고
    // 모든 자릿수가 9임을 가정했을 때
    // 생성자는 적어도 N - (각 자릿수덧셈) 보다는 커야하기 때문임

    const digits = String(i).split('').map(Number);
    const M = digits.reduce((acc, num) => {
        return acc + num
    }, i)

    //분해합을 했을 때 N 이 나오면 해당 생성자를 리턴
    if (N === M) return i;
  }

  return 0;
}

console.log(solution(input));
