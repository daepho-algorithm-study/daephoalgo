const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

// 구현한 덱
class Deque {
  constructor(initialArray = []) {
    this.storage = {};
    this.front = 0;
    this.rear = 0;

    if (Array.isArray(initialArray)) {
      initialArray.forEach((element, i) => {
        this.storage[this.rear] = { index: i + 1, paper: element };
        this.rear++;
      });
    }
  }

  length() {
    return this.rear - this.front;
  }

  push_back(element) {
    this.storage[this.rear] = element;
    this.rear++;
  }

  push_front(element) {
    this.front--;
    this.storage[this.front] = element;
  }

  pop_front() {
    if (this.length() === 0) return undefined;
    const element = this.storage[this.front];
    delete this.storage[this.front];
    this.front++;
    return element;
  }

  pop_back() {
    if (this.length() === 0) return undefined;
    this.rear--; //rear는 마지막 요소 **다음번**을 가리키고 있어서 먼저 줄여줘야 함
    const element = this.storage[this.rear];
    delete this.storage[this.rear];
    return element;
  }

  toArray() {
    const result = new Array();
    for (let i = this.front; i < this.rear; i++) {
      result.push(this.storage[i]);
    }
    return result;
  }
}

// 백준의 메모리 제한으로 인해 node.js만 플레티넘급으로 난이도가 뛰는 것 같음
// 해당 코드는 메모리 제한으로 실패했으며, 이 코드를 그대로 파이썬으로 옮겨서 겨우 통과함

// 핵심은 풍선들을 덱에 놓고 이동하는 수만큼 pop, push를 해주면 되는 것

function solution(input) {
  const N = input[0][0],
    balloons = new Deque(input[1]);
  const answer = new Array();

  // 첫 번째 풍선이 바로 터지므로 이동하는 수는 0으로 초기화
  let move = 0; 

  //풍선이 다 터질 때 까지
  while (balloons.length() > 0) {

    // 초기 (1번째 풍선)만 아래 코드를 통과함
    if (move !== 0) {
      const K = balloons.length();

      // 방향을 고려하지 않은 실제 움직이는 거리
      let real_move;

      // 종이에 양수가 나왔다면
      if (move > 0) {

        // 그 수에서 1을 빼고 현재 풍선덱 길이 모듈연산을 함
        // 1을 빼는 이유는 풍선을 터뜨리면서 배열 길이가 1 줄었기 때문임
        // 그리고 이동 할 때 길이가 초과되면 다시 처음으로 되돌아가서 마저 이동하기 때문에 모듈 연산을 함
        // 실질적으로 이동하는 거리는 그 나머지가 됨
        real_move = (move - 1) % K;

        // 오른쪽으로 이동하는 경우는
        for (let i = 0; i < real_move; i++) {

          //맨 앞의 수를 맨 뒤에 넣으면 1칸 이동하는것과 같음
          // 예제1의 3 2 1 -3 -1를 예로 들면 (1, 2, 3, 4, 5)
          // 맨 앞 1을 터뜨리고 오른쪽으로 3을 가야하므로
          // 이미 1이 터져 길이가 1 줄었으므로 2만큼 옮기면
          // 4, 5, 2, 3 순으로 나옴
          // 그러면 맨 앞 4가 그다음 터질 풍선이 되는 것임
          balloons.push_back(balloons.pop_front());
        }
      } else {

        // 반대의 경우는 1을 빼줄 필요갸 없음
        // pop_front의 경우가 오른쪽으로 이동하는것과 같기 때문에 -1을 해주는 것이고
        // pop_back은 왼쪽으로 이동하는거라 -1을 할 필요가 없음
        // 따라서 이동할 값의 절대값으로 길이를 모듈연산해주면 됨
        // 그 후 pop_back을 하고 다시 front에 push하면 왼쪽으로 1칸 이동하는것이 됨
        real_move = Math.abs(move) % K;
        for (let i = 0; i < real_move; i++) {
          balloons.push_front(balloons.pop_back());
        }
      }
    }

    // 풍선 터뜨리기
    const current = balloons.pop_front();
    answer.push(current.index);
    move = current.paper;
  }

  return answer.join(" ");
}

console.log(solution(input));
