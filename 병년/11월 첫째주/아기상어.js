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
  const N = input[0];
  let arr = input.slice(1).map((line) => line.split(" ").map(Number));

  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];
  // 초기 상어의 크기
  let size = 2;
  // 잡아 먹은 물고기 수
  let cnt = 0;
  // 먹을 수 있는 물고기 체크용 BFS 함수
  const bfs = (x, y, time) => {
    let queue = [[x, y, time]];
    let head = 0;
    const visited = Array.from({ length: N }, () => Array(N).fill(false));
    visited[x][y] = true;
    const newArr = [];

    while (queue.length > head) {
      const [cx, cy, time] = queue[head++];

      for (let k = 0; k < 4; k++) {
        let nx = cx + dx[k];
        let ny = cy + dy[k];

        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
          // 만약 다음 물고기를 먹을 수 있다면 먹는 조건 : 0 이 아니고 아직 상어의 크기가 더 크다면
          if (arr[nx][ny] > 0 && size > arr[nx][ny]) {
            // 먹을 수 있는 물고기의 좌표와 걸리는 시간 추가
            newArr.push([nx, ny, time + 1]);
            // 방문 체크
            visited[nx][ny] = true;
          }
          // 다음 칸으로 이동이 가능하다면 조건 : 크기가 아직 더 크거나 같을 경우
          if (size >= arr[nx][ny]) {
            // 계속 탐색 진행
            queue.push([nx, ny, time + 1]);
            visited[nx][ny] = true;
          }
        }
      }
    }
    // 먹을 수 있는 물고기의 좌표와 걸리는 거리가 담긴 배열 반환
    return newArr;
  };
  // 상어의 현재 위치를 찾는 함수
  const findShark = () => {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (arr[i][j] === 9) return [i, j];
      }
    }
  };
  // 결과 값 정의
  let answer = 0;

  // 어떤 물고기 부터 먹을 지 판별하는 함수
  const findCanEat = (x, y) => {
    // bfs 를 통해 먹을 수 있는 물고기의 배열 가져오기
    const fishes = bfs(x, y, 0);
    // 만약 먹을 수 있는 물고기가 없디면 바로 0 반환
    if (fishes.length === 0) return 0;

    // 정렬 조건 1. 먹을 수 있는 물고기가 여러 마리일 경우 가장 위의 물고기 먼저 먹기
    fishes.sort((a, b) => {
      if (a[2] !== b[2]) return a[2] - b[2];
      if (a[0] !== b[0]) return a[0] - b[0];
      // 그러한 물고기가 여러마리라면 맨 왼쪽의 물고기부터 먹기
      return a[1] - b[-1];
    });
    // 우선순위 반환
    return fishes[0];
  };
  let where = findShark();
  // 물고기 먹는 함수
  const eat = (x, y, time) => {
    // 물고기 먹어서 없애기
    arr[x][y] = 0;
    // 잡아먹은 물고기 누적
    cnt += 1;
    // 만약 잡아먹은 물고기가 현재 상어의 크기와 동일하다면
    if (cnt === size) {
      // 사이즈를 키우고 물고기 누적 초기화
      size++;
      cnt = 0;
    }
    // 현재 물고기의 위치 갱신
    where = [x, y];
    // 결과 값에 시간 누적
    answer += time;
  };
  // 상어 이동 표시
  arr[where[0]][where[1]] = 0;
  while (true) {
    // 상어가 먹을 수 있는 물고기 찾기
    const target = findCanEat(where[0], where[1]);
    // 먹을 수 있는 물고기가 없으면 탐색 종료
    if (!target) break;
    // 물고기의 좌표와 시간이 담긴 값 찾기
    const [nx, ny, time] = target;
    // 물고기 먹기
    eat(nx, ny, time);
  }
  console.log(answer);
};
solution(input);
