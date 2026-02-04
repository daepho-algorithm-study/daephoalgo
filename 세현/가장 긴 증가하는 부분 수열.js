const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, A) {
  // lis 배열에서는 실제 부분 수열을 관리하는 게 아니라 각 길이별 증가 수열의 가장 유리한 끝값만 관리함
  // 새로운 값이 오면 붙일 수 있으면 붙이고, 못 붙이면 더 좋은 끝값으로 교체만 함
  // 원본 수열 복원 로직으로 쓰기는 부족하고, 길이만 계산하는 용도로 쓸 수 있음
  const lis = [];

  // 현재까지 만들어진 LIS의 마지막 위치 (lis.length - 1과 동일한 의미)
  let idx = 0;

  // lis에다가 원본 수열의 맨 처음 요소를 집어넣음
  lis.push(A[idx]);

  // 그 후 반복문 돌면서 원본 수열을 하나씩 비교함
  for (let i = 1; i < N; i++) {

    // 현재 값 A[i]가 lis의 마지막 값보다 크면
    // 기존 수열 뒤에 붙일 수 있음
    if (lis[idx] < A[i]) {
      // 조건을 만족하면 LIS 뒤에 추가함
      lis.push(A[i]);

      // LIS 마지막 위치를 옮겨줌
      idx++;

    } else {

      // A[i]가 lis의 마지막 값보다 작거나 같다면 적절한 위치를 찾아 교체해야 함
      // 부분 수열의 맨 뒤에서 부터 거슬러 올라가면서 검사함
      for (let j = idx; j >= 0; j--) {

        // 만약 비교되는 요소보다 작은 수가 lis에 없거나
        // 원본 배열에서 바라보는 수 A[i]보다 작은 요소가 lis의 j-1 번째에 위치한다면
        if (j === 0 || lis[j - 1] < A[i]) {

          // lis 의 j 번째를 해당 요소로 변경함
          lis[j] = A[i];
          break;

          // 원래 j번째 뒤의 값들을 유지시켜놓는 이유는
          // 이미 교체하기 전에 이미 해당 값들로 이루어진 수열이 현재의 최대 길이이기 때문
          // 이렇게 하면 길이는 유지되고 끝값만 더 좋은 후보로 갱신됨
          // 수열의 관점이 아니라 길이의 관점으로 봐야됨
        }
      }
    }
  }

  return lis.length;
}

console.log(solution(input[0][0], input[1]));
