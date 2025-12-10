const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", 'utf-8')
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const answer = [];
  const N = input[0][0]
  const que_stack = input[1];
  const real_arr = input[2];
  const M = input[3];
  const input_nums = input[4];

  // 이 문제는 스택과 큐를 뒤섞어놓은 문제로 규칙만 잘 파악하면 쉬움
  // 스택일 경우는 입력한 값이 바로 튀어나오고
  // 큐일 경우엔 원래 자료구조 안에 있던 값을 밀어내고 자기가 들어감
  // 그리고 pop 된 값이 새로운 입력값이 됨
  // 때문에 stack 일 경우엔 건너뛰어주고 큐일 경우에만 처리해주면 됨
  // 최종적으로는 이 자료구조의 맨 뒤쪽 큐의 값들부터 쭉 들어가고
  //  수열(C)의 원소들 앞의 값부터 차례대로 들어가는 형태가 됨
  /*
    0 1 1 0 : 0이면 큐, 1이면 스택
    1 2 3 4 : 원래 배열 앞의 값=
    2 4 7   : 수열 C
    큐(0)에 해당하는 원소값 뒤에서부터 (4, 1) 이어주고
    수열 C를 앞에서부터 채워넣어주면 최종 아웃풋은 (4, 1, 2, 4, 7)
    여기서 입력되는 수는 수열 C의 길이만큼이니까 그만큼만 자르면 됨
    위 예시에선 3이므로 3번째 까지만 해당됨(4, 1, 2)
  */

  // 뒤에서부터 차례대로 검사하면서(마지막 큐의 값부터 차례대로 나오니깐)
  for (let i = N-1; i >= 0; i--) {
    // 해당 자료구조가 큐이면 결과에 붙이기
    if (que_stack[i] === 0) {

      // 
        answer.push(real_arr[i])
    }
  }
  // 입력값 차례대로 결과에 붙이기
  for (let i = 0; i < M; i++) {
    answer.push(input_nums[i]);
  }
  // 수열 길이만큼 자른 게 정답이 됨
  return answer.slice(0, M).join(" ");
}

console.log(solution(input));
