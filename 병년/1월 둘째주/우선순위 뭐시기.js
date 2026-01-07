function solution(priorities, location) {
  let queue = priorities.map((value, index) => [value, index]);
  let cnt = 0;
  while (queue.length) {
    let [prioritie, index] = queue.shift();
    if (queue.some(([p]) => p > prioritie)) {
      queue.push([prioritie, index]);
    } else {
      cnt++;
      if (index === location) return cnt;
    }
  }
}
