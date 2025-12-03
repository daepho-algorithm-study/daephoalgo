const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map(Number));

// console.log(input);

class Deque {
  constructor() {
    this.storage = {};
    this.front = 0;
    this.rear = 0;
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

function solution(input) {
  const N = input[0][0];
  const deque = new Deque();
  const answer = new Array();
  for (let i = 1; i <= N; i++) {
    switch (true) {
      case input[i][0] === 1:
        deque.push_front(input[i][1]);
        break;
      case input[i][0] === 2:
        deque.push_back(input[i][1]);
        break;
      case input[i][0] === 3:
        answer.push(deque.length() > 0 ? deque.pop_front() : -1);
        break;
      case input[i][0] === 4:
        answer.push(deque.length() > 0 ? deque.pop_back() : -1);
        break;
      case input[i][0] === 5:
        answer.push(deque.length());
        break;
      case input[i][0] === 6:
        answer.push(deque.length() === 0 ? 1 : 0);
        break;
      case input[i][0] === 7:
        answer.push(deque.length() > 0 ? deque.storage[deque.front] : -1);
        break;
      case input[i][0] === 8:
        answer.push(deque.length() > 0 ? deque.storage[deque.rear - 1] : -1);
        break;
    }
  }
  return answer.join("\n");
}

console.log(solution(input));
