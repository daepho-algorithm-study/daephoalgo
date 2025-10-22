const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split(" ")
  .map((e) => Number(e));

// console.log(input);

function solution(input) {
  let [A, B, V] = input;
  // (올라가는 거리 - 떨어지는 거리) 가 실제 하루 이동거리임
  // 실제 총 거리는 떨어지는 거리를 한번 빼줘야 함 --> 마지막날엔 다올라와서 떨어지지 않으니까
  const realV = V - B;
  // 실제 총 거리에서 하루 실질 이동 거리를 나눠주면 됨
  const x = realV / (A-B);
  const y = parseInt(x);
  // 만약 정수로 딱 나누어떨어지면 그 일수가 정답이 됨
  // 정수로 안나누어 떨어지면 정수부분 일수에서 몇시간 더 가야하는 것이므로 하루를 더 체크해 주어야 함
  const day = y === x ? y : y+1;
  return day;
}

console.log(solution(input));
