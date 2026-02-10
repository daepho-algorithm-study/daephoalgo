function solution(order) {
  var answer = 0;
  const queue = [];
  for (let i = 1; i < order[0]; i++) {
    queue.push(i);
  }
  let result = 1;
  while (queue.length > 0) {
    let idx = 1;
    let next = queue.shift();

    if (order[idx] === next) {
      result++;
      idx++
    } else {
      break;
    }
  }
  return answer;
}
