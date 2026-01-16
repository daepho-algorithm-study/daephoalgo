const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let n = Number(input[0]);
  // 0 이 입력으로 들어오면 리턴
  if (n === 0) {
    console.log("NO");
    return;
  }
  while (0 < n) {
    /**
     * n 에서 3을 나눈 값이 2 일 때가 의미하는 것은
     * 3진수의 관점에서 봤을 때 2가 나오면 해당 자리의 수를
     * 2번 썼다는 의미이기 때문에 규칙에 위배됨 따라서 2가 나오면
     * NO 출력 후 return
     * 예를 들어서 n 이 18일 때
     * case 1 : n / 3 = 6 n % 3 = 0
     * case 2 : n / 3 = 2 n % 3 = 0
     * case 3 : n / 3 = 0.66... n % 3 = 2
     * 이런 식으로 나오게 되는데 이를 3진수로 표현하면 200 이 된다 
     * 이 200의 의미는 3 ** 2 를 2번 썼다는 의미 이므로 9 + 9 
     * 해당 문제의 규칙에 위배 되게 된다.
     */
    if (n % 3 === 2) {
      console.log("NO");
      return;
    }
    n = Math.floor(n / 3);
  }
  console.log("YES");
};

solution(input);
