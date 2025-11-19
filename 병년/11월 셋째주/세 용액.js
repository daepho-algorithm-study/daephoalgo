const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input[0]);
  const arr = input[1].split(" ").map(Number);

  arr.sort((a, b) => a - b);

  const tp = () => {
    let mn = Infinity;
    let result = [];
    // 세 용액 중 맨 처음 값에서 두 개를 뽑아 즉 3개를 만들어 더하기 위한 반복문
    /**
     * ex) arr = -97, -6, -2, 6, 98
     * i === 1
     * start = -6
     * arr[i] = -97
     * arr[end] = 98
     * sm = -5
     * mn = -5
     * result = [-97, -6, 98]
     * sm < 0 === true
     * start++
     * start = -2
     * arr[i] = -97
     * arr[end] = 98
     * sm = -1
     * mn = -1
     * result = [-97, -2, 98]
     * sm < 0 === true
     * start++
     * 이런식으로 진행됨
     **/
    for (let i = 0; i < N - 2; i++) {
      // 시작 값은 초기 값에서 +1 한 값
      let start = i + 1;
      // 끝 값은 가장 끝 값
      let end = N - 1;
      // 투 포인터 탐색 시작
      while (start < end) {
        // 세 용액 합산
        let sm = arr[i] + arr[start] + arr[end];
        // 최소값 갱신
        if (Math.abs(sm) < mn) {
          mn = Math.abs(sm);
          // result 에 재할당
          result = [arr[i], arr[start], arr[end]];
        }
        // 세 용액을 합친 값이 0 보다 크면 start 를 늘리기
        if (sm < 0) {
          start++;
          // 아니라면 end 를 줄이기
        } else {
          end--;
        }
      }
    }
    return result;
  };
  let result = tp();
  console.log(result.join(" "));
};
solution(input);
