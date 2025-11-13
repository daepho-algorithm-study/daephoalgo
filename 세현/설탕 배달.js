const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  let N = input[0];
  let answer = -1;
  // 배달무게가 3이나 5면 바로 1봉지로 리턴
  if (N === 3 || N === 5) {
    return 1;
  }
  
  // 설탕이 5kg, 3kg 단위로 있다면
  // 먼저 5kg 단위부터 최대로 잡아주면 좀 더 빠르게 최소 개수를 찾을 수 있음
  if (N > 5) {
    // 봉지 개수 초기화
    let current = 5000;

    // 가능한 5kg 봉지의 최대 개수를 초기값으로 반복문을 돌림
    let five = Math.floor(N / 5);

    while (five >= 0) {
      // 총 무게에서 현재 5의 배수를 뺀 나머지가 3으로 나누어 떨어지면 정답 후보가 됨
      const rest = N - five * 5;
      if (rest % 3 === 0) {

        // 최소값으로 한번 더 걸러줌
        current = Math.min(current, five + rest / 3);
      }

      // 현재의 5kg 봉지 수를 하나씩 낮춰가면서 반복함
      five--;
    }

    // 현재 봉지 개수가 초기값이 아니면 정답이 나왔다는 뜻
    if (current < 5000) {
      answer = current;
    }
  }
  return answer;
}

console.log(solution(input));
