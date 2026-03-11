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
  const T = Number(input[idx++]);
  for (let tc = 0; tc < T; tc++) {
    const parent = [];
    // 루트 노드의 네트워크 크기
    const size = [];
    // 문자열 이름 -> 숫자 인덱스 변환을 위한 Map
    const map = new Map();
    // 루트 노드 찾기
    const find = (x) => {
      // 자기 자신이 부모가 아니라면
      if (parent[x] !== x) {
        // 재귀호출로 부모 찾기
        parent[x] = find(parent[x]);
      }
      // 루트 노드 반환
      return parent[x];
    };
    // 합치기
    const union = (a, b) => {
      let a1 = find(a);
      let b1 = find(b);

      // 이미 같은 네트워크면 사이즈 바로 반환
      if (a1 === b1) return size[a1];
      // 작은 트리를 큰 트리밑으로 붙이기 << 루트끼리 맞짱
      if (size[a1] < size[b1]) {
        [a1, b1] = [b1, a1];
      }
      // b의 루트를 a 루트 밑으로 붙이기
      parent[b1] = a1;
      // 네크워크 크기 늘리기
      size[a1] += size[b1];
      // 반환
      return size[a1];
    };
    const getIndex = (name) => {
      // 아직 없는 이름이라면
      if (!map.has(name)) {
        // 인덱스 생성
        const idx = map.size;
        // 맵에 저장
        map.set(name, idx);
        // 자기 자신을 부모로 설정
        parent[idx] = idx;
        // 네트워크 크기 1로 할당
        size[idx] = 1;
      }
      return map.get(name);
    };
    const F = Number(input[idx++]);
    for (let i = 0; i < F; i++) {
      const [a, b] = input[idx++].split(" ");
      const ai = getIndex(a);
      const bi = getIndex(b);
      console.log(union(ai, bi));
    }
  }
};
solution(input);
