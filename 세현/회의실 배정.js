const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, meetings) {
  let answer = 0;

  // 끝나는 시간 기준 오름차순 정렬, 같으면 시작 시간 기준 정렬
  meetings.sort((a, b) => {
    if (a[1] === b[1]) {
      return a[0] - b[0];
    } else {
      return a[1] - b[1];
    }
  });

  // 회의실이 비는 시간
  let vacancy = 0;

  for (let i = 0; i < N; i++) {

    // 현재 회의 시작 시간이 vacancy 이상이면 회의 배정 가능
    if (meetings[i][0] >= vacancy) {
      
      answer += 1;
      vacancy = meetings[i][1]; // vacancy를 현재 회의 종료 시간으로 갱신
    }
  }

  return answer;
}

console.log(solution(input[0][0], input.slice(1)));
