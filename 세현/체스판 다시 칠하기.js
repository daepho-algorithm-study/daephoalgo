const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  // 초기값을 크게 세팅 (최솟값으로 갱신하기 위해)
  let answer = 65;
  const size = input[0].split(" ").map(Number);
  // N : 세로 길이, M : 가로 길이
  const N = size[0], M = size[1];

    // input의 첫 번째 줄은 N, M 정보임. 두 번째 줄부터 체스판 시작
    // input[1] ~ input[N] 까지가 세로이고 input[][0] ~ input[][M-1] 까지가 가로임
    for (let i = 1; i <= N-8+1; i++) {
        for (let j = 0; j <= M-8; j++) {
          // 8*8 체스판을 잘라낸 모든 경우의 수를 검사할 것임

            // 잘라낸 체스판의 스타트 지점(맨 왼쪽 위)이 W로 시작하는지, B로 시작하는지
            // 두 가지 패턴 모두 검사해야 함 (중요!!)
            let patternW = 0;
            let patternB = 0;
            // 스타트 지점이 W로 시작했을 때 고쳐야 할 개수와 B로 시작했을 때 고쳐야 할 개수

            // 각 체스판을 돌아주면서
            for (let sero = i; sero < i+8; sero++) {
                for (let garo = j; garo < j+8; garo++) {
                    // 체스판각 칸의 색은 가로인덱스와 세로인덱스의 합이 홀짝인지를 검사해 주면 됨
                    if ((garo+sero) % 2 === 1) {
                      //만약 조건문이 홀수이면 체스판으로 봤을 때 스타트 지점 부터 띄엄띄엄 가는 패턴에 해당함

                        // B부터 시작하는 체스판이면 스타트 지점부터 띄엄띄엄 가는 모든 칸은 B이여야 하는데
                        // 그 칸이 W로 칠해져있으면 잘못된 것이므로 카운팅 해줌
                        if (input[sero][garo] === 'W') patternB += 1;

                        // 마찬가지로 W부터 시작하는 체스판이면 해당 칸들은 W로 칠해져 있어야 하는데
                        // 그 칸이 B로 칠해져있으면 잘못된 것이므로 카운팅 해줌
                        if (input[sero][garo] === 'B') patternW += 1;

                    } else {
                      // 체스판으로 봤을 때 스타트지점의 다음 칸 부터 띄엄띄엄 가는 패턴에 해당함

                        // 위 로직과 동일함
                        if (input[sero][garo] === 'W') patternW += 1;
                        if (input[sero][garo] === 'B') patternB += 1;
                    }
                }
            }
            
            answer = Math.min(answer, patternW, patternB);
            
        }
    }

  return answer;
}

console.log(solution(input));
