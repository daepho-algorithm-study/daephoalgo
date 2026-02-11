const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N, A) {
  // i에서 끝나는 증가 부분 수열 길이 저장 배열
  const dpinc = Array.from({ length: N }, () => 1);

  // i에서 시작하는 감소 부분 수열 길이 저장 배열
  const dpdec = Array.from({ length: N }, () => 1);

  // 증가 부분 수열(LIS) 구하는 부분
  // i 이전의 원소들(j < i)을 보면서
  // A[j] < A[i] 이면 이어 붙일 수 있으므로 길이 갱신
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < i; j++) {
      if (A[i] > A[j]) {
        // 기존 값 vs j를 거쳐서 오는 경우 중 최댓값 선택
        dpinc[i] = Math.max(dpinc[i], dpinc[j] + 1);
      }
    }
  }

  // 감소 부분 수열 구하는 부분
  // 뒤에서부터 탐색
  // i 이후의 원소들(j > i)을 보면서
  // A[j] < A[i] 이면 감소 수열로 이어 붙일 수 있음
  for (let i = N - 1; i >= 0; i--) {
    for (let j = N - 1; j > i; j--) {
      if (A[i] > A[j]) {
        // 기존 값 vs j를 거쳐서 오는 경우 중 최댓값 선택
        dpdec[i] = Math.max(dpdec[i], dpdec[j] + 1);
      }
    }
  }

  // 각 인덱스를 꼭짓점으로 하는 바이토닉 수열 길이 계산
  // 증가 길이 + 감소 길이 - 1 (서로 끝부분이 한번 중복되므로 1 빼줌)
  let answer = 0;
  for (let i = 0; i < N; i++) {
    answer =
      answer > dpinc[i] + dpdec[i] - 1
        ? answer
        : dpinc[i] + dpdec[i] - 1;
  }

  // 최장 바이토닉 부분 수열 길이 반환
  return answer;
}

console.log(solution(input[0][0], input[1]));
