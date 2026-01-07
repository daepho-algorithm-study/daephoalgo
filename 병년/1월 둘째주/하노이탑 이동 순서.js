const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let answer = [];
  const N = Number(input[0]);
  /**
   * 하노이탑의 경우 가장 큰 원판을 목표할 위치에 먼저 놓고 다른 원판을
   * 치우는 식으로 진행이 됨
   * 따라서 가장 큰 원판을 C 에 놓기 위해서는 그 위에 있는 원판을
   * B에 먼저 놓고 더 이상 놓을 원판이 없을 때
   * 가장 큰 원판을 C 에 놓은 후 이제 남은 원판을 C에 다시 놓는 방식
   */
  const recur = (cnt, start, mid, to) => {
    // 이동할 수 있는 원반의 수가 1개일 때 출력
    if (cnt === 1) {
      answer.push(`${start} ${to}`);
      return;
    }
    // N - 1 의 원판을 A -> B 로 옮기는 함수
    recur(cnt - 1, start, to, mid);
    // N 원판을 C로 옮겼으니 출력
    answer.push(`${start} ${to}`);
    // N - 1 의 원판을 B -> C 로 옮기는 함수
    recur(cnt - 1, mid, start, to);
  };

  // 가장 큰 원판과 시작 중간 끝 설정
  recur(N, 1, 2, 3);
  console.log(answer.length);
  process.stdout.write(answer.join("\n") + "\n");
};
solution(input);
