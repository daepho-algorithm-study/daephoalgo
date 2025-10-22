const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  const N = input[0];
  // base = 현재까지 누적된 방의 개수에 해당함. 중앙에서부터(1개부터) 누적됨.
  base = 1;
  // cnt = 이동 거리
  cnt = 1;
  while (true) {
    if (N == 1) {
        return 1;
    }
    // 벌집은 방 개수가 1개서부터 시작해서 테두리가 늘어날 때마다 늘어난 테두리가 그 전 테두리보다 6개씩 추가됨
    // 중앙 1에서 다음 테두리는 6개, 그 다음 테두리는 12개 ... n*6개 이렇게 됨
    // 따라서 방의 개수를 n번째 테두리 * 6 개씩 누적시켜주면 총 방의 개수가 나옴
    // 입력 받은 수가 총 방의 개수보다 작으면 그 테두리 안에 있다는 뜻이므로 모든 테두리 개수 + 1(맨 처음 방 카운트) 해주면 됨
    base = base + (cnt*6);

    // 만약 방 번호가 현재까지의 테두리 안에 있다면
    if (N <= base) {
      // 테두리 개수+1 만큼 해서 리턴(맨 처음 시작부분도 카운트해야하니까) 
      return cnt+1;
    }
    //테두리를 계속 늘려나가면 됨
    cnt += 1;
  }
}

console.log(solution(input));
