const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/);
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, A, M, nums) {
  
  let answer = Array.from({ length: M }, () => 0);
  let idx = 0;

  // 이분탐색을 위한 정렬
  A.sort((a, b) => a - b);

  // 검사할 수들
  for (const num of nums) {
    
    // 범위 벗어나면 0 내버려둠
    if (num > A[N - 1] || num < A[0]) {
      idx++;
      continue;
    }

    // 왼쪽, 오른쪽 위치
    let [left, right] = [0, N - 1];

    let mid = 0;

    // 범위가 유효할때 까지 검사
    while (left <= right) {

      // 중간 값 설정
      mid = Math.floor((left + right) / 2);

      // 찾는 값이 더 작으면 오른쪽을 mid-1 로 갱신
      if (A[mid] > num) {
        right = mid - 1;

      // 찾는 값이 더 크면 왼쪽을 mid+1 로 갱신
      } else if (A[mid] < num) {
        left = mid + 1;

      // 찾는 값이면 1 넣어주고 while 종료
      } else {
        answer[idx] = 1;
        break;
      }
    }
    idx++;
  }

  return answer.join("\n").trim();
}

const N = Number(input[0]);
const A = input[1].split(" ").map(Number);
const M = Number(input[2]);
const nums = input[3].split(" ").map(Number);
console.log(solution(N, A, M, nums));
