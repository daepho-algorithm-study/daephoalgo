const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const arr = input[1];

  // js식 정렬 후 중복 제거
  const sorted = arr
    .slice()
    .sort((a, b) => a - b)
    .filter((value, idx, self) => idx === 0 || value !== self[idx - 1]);

  //const answer = arr.map(v => sorted.indexOf(v)); //시간초과 나는 방법이라 이분탐색으로 바꿈

  // 이분 탐색
  function binarySearch(arr, tar) {
    // 양 끝 지점 인덱스 지정
    let left = 0,
      right = arr.length - 1;

    // 찾을 때 까지 돌리기
    while (left <= right) {
      // 정렬된 배열의 중간 값을 뽑아서
      const mid = Math.floor((left + right) / 2);

      // 내가 찾는 값과 비교하기 -> 맞으면 반환
      if (arr[mid] === tar) return mid;
      // 아니면 그 값이 찾는 값보다 큰지 작은지 판단
      // 작다면 mid 다음부터 다시 이분 탐색
      else if (arr[mid] < tar) left = mid + 1;
      // 크다면 mid 이전까지 다시 이분 탐색
      else right = mid - 1;
    }
  }

  // 정렬하고 중복 제거한 배열의 index 값이 나보다 작은 값의 개수와 같음!!
  // 그래서 sorted의 index 값을 매칭해 주면 좌표압축이 된 것
  const answer = arr.map((v) => binarySearch(sorted, v));

  return answer.join(" ");
}

console.log(solution(input));
