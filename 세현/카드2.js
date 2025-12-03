const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

class Queue {
  constructor() {
    this.storage = {};
    this.front = 0;
    this.rear = 0;
  }

  length() {
    return this.rear - this.front;
  }

  push(element) {
    this.storage[this.rear] = element;
    this.rear++;
  }

  pop() {
    if (this.length() === 0) return undefined;
    const element = this.storage[this.front];
    delete this.storage[this.front];
    this.front++;
    return element;
  }
}

function solution(input) {
  const N = input[0];
  const queue = new Queue();

  for (let i = 1; i <= N; i++) {
    queue.push(i);
  }

  let idx = 0;
  while (queue.length() > 1) {
    if (idx % 2 === 0) {
      queue.pop();
    } else {
      queue.push(queue.pop());
    }
    idx++;
  }
  return queue.storage[queue.front];
}

console.log(solution(input));
