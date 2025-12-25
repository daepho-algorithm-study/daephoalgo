const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const N = input[0][0],
    K = input[0][1];
  const arr = input[1];
  let result = -1;
  let cnt = 0;

  // solution 내부에 함수를 선언하는 이유 -> 클로저(Closure) 활용을 위해서임
  // 클로저(Closure): "함수 본체" + "함수가 참조하고 있는 외부 변수들의 주소록"
  // 즉, 클로저는 자신이 태어난 환경을 통째로 기억하고 있어 **외부 변수를 참조** 할 수 있음
  // 때문에 부모 함수인 solution의 cnt를 내부 함수 merge_sort에서 활용할 수 있음
  // Java(8+ ver)나 C++(11+ ver)에서는 비슷하게 람다식을 통해서 외부 변수를 참조할 수 있음

  // p ->시작점  r ->끝점
  const merge_sort = (arr, p, r) => {
    if (p < r) {
      const q = Math.floor((p + r) / 2);
      merge_sort(arr, p, q); // 전반부 정렬(원본 배열이 정렬됨)
      merge_sort(arr, q + 1, r); // 후반부 정렬(원본 배열이 정렬됨)
      merge(arr, p, q, r); // 병합
    }
  };

  // p ->시작점  r ->끝점  q ->중간점
  const merge = (arr, p, q, r) => {
    let i = p,
      j = q + 1,
      t = 0;
    const tmp = [];
    // p ~ q, q+1 ~ r 배열 양쪽으로 나눠서

    //양쪽 배열(이분된 왼 배열, 오른 배열)에 요소가 남아있는 동안 비교하여 tmp에 그대로 담기
    //투 포인터 매커니즘으로 tmp 배열에 하나씩 넣어준다고 생각하면 됨
    while (i <= q && j <= r) {
      // 왼쪽 배열의 i번째와 오른쪽 배열의 j 번째를 서로 비교함
      if (arr[i] <= arr[j]) {
        // 만약 왼쪽이 더 작다면 왼쪽을 tmp 배열에 집어넣고 왼쪽 인덱스와 tmp 인덱스 증가
        // 핵심은 j 인덱스는 가만히 놔두는 것
        tmp[t++] = arr[i++];

      } else {  //반대의 경우도 마찬가지. 이 경우 i 인덱스를 가만히 놔둬야 함
        tmp[t++] = arr[j++];
      }
      // 이렇게 하면 현재 부분의 tmp 배열은 오름차순으로 정렬 됨
    }
    while (i <= q) {
      //왼쪽 배열 부분이 남은 경우 모두 옮겨주기
      tmp[t++] = arr[i++];
    }
    while (j <= r) {
      //오른쪽 배열 부분이 남은 경우 모두 옮겨주기
      tmp[t++] = arr[j++];
    }

    // 임시 배열 tmp의 결과를 원본 배열 arr의 [p...r] 구간에 복사
    i = p;
    t = 0;
    while (i <= r) {
      arr[i++] = tmp[t++];
      // 현재 저장되는 횟수를 증가
      cnt++;
      // 만약 현재 횟수가 K와 같다면 정답이 됨
      if (cnt === K) {
        result = tmp[t - 1];
      }
    }
  };

  merge_sort(arr, 0, N - 1);
  return result;
}

console.log(solution(input));
