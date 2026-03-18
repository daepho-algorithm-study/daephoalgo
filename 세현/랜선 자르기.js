const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, K, lans) {
  let answer = 0;

  // left = 0으로 하면 터짐. 1 으로 둘 것
  let [left, right] = [1, Math.max(...lans)]
  
  // 범위가 존재할 때까지 탐색
  while (left <= right) {

    // 중간 값 몫연산
    const middle = ~~((left + right) / 2)

    // 현재 길이로 잘랐을 때 랜선 개수
    let total = 0
    for (let i = 0; i < K; i++) {
      total += ~~(lans[i] / middle);
    }

    // 개수가 모자라면 길이가 더 작아야 함
    if (total < N) {
      right = middle - 1;

    // 개수가 충분하면 길이가 더 커도 됨
    } else {

      // 갈이 최대값으로 갱신
      answer = middle;
      left = middle + 1;
    }
  }

  return answer;
}

const [K, N] = input[0].split(" ").map(Number);
const lans = input.slice(1).map(Number);
console.log(solution(N, K, lans));
