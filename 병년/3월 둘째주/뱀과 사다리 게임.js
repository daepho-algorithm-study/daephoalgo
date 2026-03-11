const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);
  // 뱀과 사다리를 정의할 객체 생성
  const obj = {};
  // 방문 체크 배열
  const visited = Array(101).fill(false);

  // 객체에 뱀과 사다리 정보 넣기
  for (let i = 0; i < N + M; i++) {
    const [from, to] = input[idx++].split(" ").map(Number);
    obj[from] = to;
  }
  // bfs 수행
  const bfs = () => {
    // queue에 cur, depth 초기값 삽입
    const queue = [[1, 0]];
    let head = 0;
    while (head < queue.length) {
      // 맨 앞에 있는 값 뽑아오기
      let [cur, depth] = queue[head++];
      // 현재값이 100이라면 depth 반환
      if (cur === 100) {
        return depth;
      }
      // 1 ~ 6 주사위 굴려보기
      for (let i = 1; i <= 6; i++) {
        // 현재 값에 돌린 주사위 눈 추가
        let next = cur + i;
        // 만약 다음 값이 100 이 넘어가면 무시
        if (next > 100) continue;
        // 객체 내부에 뱀이나 사다리에 걸리면 다음값 할당
        if (obj[next]) {
          next = obj[next];
        }
        // 아직 방문한 적이 없는 좌표라면
        if (!visited[next]) {
          // 방문 체크 후 다음값과 depth 값 queue에 추가
          visited[next] = true;
          queue.push([next, depth + 1]);
        }
      }
    }
  };

  let answer = bfs();
  console.log(answer);
};
solution(input);
