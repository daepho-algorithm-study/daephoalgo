const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

function solution(N, M, trees) {
  // 이분 탐색 범위 설정
  let [left, right] = [0, Math.max(...trees)];

  // 최적 값
  let maxHeight = 0;

  // 중간 값
  let mid = ~~((left + right)/2);

  // 범위가 유효할 때 까지 계속
  while(left <= right) {

    // 조건 값(M만큼 되는지)
    let lumb = 0;

    // 나무들 잘라서 다 더해보기 (절단기 높이 이상 나무만 해당)
    for (let i = 0; i < N; i++) {
      lumb += (trees[i] - mid) < 0 ? 0 : trees[i] - mid;
    }

    // 못 미치면 절단기 높이 낮추기
    if (lumb < M) {
      right = mid - 1;

    // 남으면 절단기 높이 높이기
    } else {
      // 현재 절단기 높이 저장
      maxHeight = mid;
      left = mid + 1;
    }

    // 중간 값 갱신
    mid = ~~((left + right) / 2)
  }
  

  return maxHeight;
}

const [N, M] = input[0].split(" ").map(Number);
const trees = input[1].split(" ").map(Number);

console.log(solution(N, M, trees));
