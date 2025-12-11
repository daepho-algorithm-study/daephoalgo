const solution = (begin, target, words) => {
  // 단어 체크용 함수
  const isSet = (a, b) => {
    let cnt = 0;
    // 만약 단어가 다르다면 개수 증가
    for (let i = 0; i < a.length; i++) {
      if (a[i] !== b[i]) {
        cnt++;
      }
    }
    // 다른 단어의 개수가 1개라면 true 아니라면 false 반환
    if (cnt === 1) return true;
    else return false;
  };
  // 중복 제거용 set
  let visited = new Set();
  const bfs = () => {
    visited.add(begin);
    let queue = [[begin, 0]];
    let head = 0;

    while (queue.length > head) {
      let [next, depth] = queue[head++];
      // 현재 단어가 target 이라면 depth 반환
      if (next === target) {
        return depth;
      }
      // 단어 배열 순회
      for (let word of words) {
        // 배열 내부 원소와 현재 단어가 한 단어 차이이고 방문 한 적이 없으면
        if (isSet(next, word) && !visited.has(word)) {
          // 방문 처리
          visited.add(word);
          // 다음 단어 탐색 및 depth 추가
          queue.push([word, depth + 1]);
        }
      }
    }
    return 0;
  };
  let result = bfs();
  return result;
};
