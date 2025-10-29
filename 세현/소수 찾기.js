const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

// console.log(input);

function solution(input) {
  const inp = input[1].split(" ").map((e) => Number(e));
  let answer = 0;
  // 제곱근 방식으로 소수를 판별하면 시간복잡도가 √n으로 확 줄어듬
  inp.forEach((n) => {
    if (n > 1) {
        let flag = true;
        //범위를 √n까지만 검사. 나머지 범위는 하나마나 똑같음
        for (let i = 2; i*i <= n; i++) {
            if (n % i === 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer += 1
        }
    }
  })

  return answer;
}

console.log(solution(input));
