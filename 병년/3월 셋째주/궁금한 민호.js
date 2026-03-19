const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);

  // 입력으로 주어진 "최단 거리 행렬"
  const dist = [];

  // 실제로 필요한 간선만 남길 배열 (초기에는 모두 유지한다고 가정)
  const arr = Array.from({ length: N }, () => Array(N).fill(0));

  // 거리 행렬 입력
  for (let i = 0; i < N; i++) {
    const dists = input[idx++].split(" ").map(Number);
    dist.push(dists);
  }

  // arr에 dist 값 복사 (초기 상태: 모든 간선 존재)
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      arr[i][j] = dist[i][j];
    }
  }

  // 플로이드-워셜 기반 검증 + 불필요한 간선 제거
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        // 자기 자신이거나 같은 노드 포함하는 경우는 스킵
        if (i === j || i === k || k === j) {
          continue;
        }

        // [1] 모순 검사
        // 직접 가는 거리보다 k를 거치는 게 더 짧으면
        // 입력 자체가 잘못된 "최단 거리 행렬"
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          console.log(-1);
          return;
        }

        // [2] 불필요한 간선 제거
        // k를 경유해도 같은 거리라면 i → j 직접 간선은 필요 없음
        if (dist[i][j] === dist[i][k] + dist[k][j]) {
          arr[i][j] = Infinity; // 제거 표시
        }
      }
    }
  }

  let answer = 0;

  // 무방향 그래프이므로 간선 중복 방지를 위한 체크 배열
  const check = Array.from({ length: N }, () => Array(N).fill(false));

  // 남아있는 간선들만 더하기
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      // 제거된 간선 / 자기 자신 / 이미 더한 간선은 제외
      if (arr[i][j] === Infinity || arr[i][j] === 0 || check[i][j]) {
        continue;
      }

      // 간선 비용 더하기
      answer += arr[i][j];

      // 반대 방향도 같은 간선이므로 중복 방지 처리
      check[j][i] = true;
      check[i][j] = true;
    }
  }

  // 최종: 필요한 간선들의 총 비용
  console.log(answer);
};

solution(input);
