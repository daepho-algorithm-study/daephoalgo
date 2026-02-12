// function solution(order) {
//   var answer = 0;
//   const queue = [];
//   for (let i = 1; i < order[0]; i++) {
//     queue.push(i);
//   }
//   let result = 1;
//   while (queue.length > 0) {
//     let idx = 1;
//     let next = queue.shift();

//     if (order[idx] === next) {
//       result++;
//       idx++
//     } else {
//       break;
//     }
//   }
//   return answer;
// }
function solution(order) {
  const stack = [];
  let result = 0;
  let idx = 0;
  // 일단 1부터 order 까지 반복 돌면서 보조 컨테이너 벨트에 넣어보기
  for (let i = 1; i <= order.length; i++) {
    stack.push(i);
    // 보조 컨테이너 벨트가 비어있지 않다면
    while (stack.length > 0) {
      // 다음에 꺼낼 상자를 확인하기
      let next = stack[stack.length - 1];
      // 만약 다음에 꺼낼 상자와 order 의 상자와 일치하면
      if (order[idx] === next) {
        // 결과값 하나 올리고 스택에서 제거하기
        result++;
        stack.pop();
        // 다음 order를 볼 수 있도록 idx 값 추가
        idx++;
        // 아니라면 주문 내역 확인할 필요 없음
      } else {
        break;
      }
    }
  }
  return result;
}

const answer = solution([4, 3, 1, 2, 5]);
console.log(answer);
