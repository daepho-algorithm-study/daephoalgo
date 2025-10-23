function solution(k, tangerine) {
  var answer = 0;
  let obj = {};
  tangerine.forEach((value) => {
    obj[value] = (obj[value] || 0) + 1;
  });
  let tangerines = Object.values(obj).sort((a, b) => b - a);

  let sum = 0;

  for (let tan of tangerines) {
    if (sum >= k) break;
    sum += tan;
    answer++;
  }

  return answer;
}
