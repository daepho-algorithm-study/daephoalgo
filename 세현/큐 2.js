const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  //   .map((e) => Number(e));
  .map((line) => line.split(" ").map((element) => element.trim()));

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
    if (this.length() === 0) {
      return undefined;
    }
    const element = this.storage[this.front];
    delete this.storage[this.front];
    this.front++;
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
  const answer = new Array();
  const queue = new Queue();
  const N = Number(input[0][0]);
  for (let i = 1; i <= N; i++) {
    switch (true) {
      case input[i][0] === "push":
        queue.push(Number(input[i][1]));
        break;
      case input[i][0] === "pop":
        answer.push(queue.length() > 0 ? queue.pop() : -1);
        break;
      case input[i][0] === "size":
        answer.push(queue.length());
        break;
      case input[i][0] === "empty":
        answer.push(queue.length() === 0 ? 1 : 0);
        break;
      case input[i][0] === "front":
        answer.push(queue.length() > 0 ? queue.storage[queue.front] : -1);
        break;
      case input[i][0] === "back":
        answer.push(queue.length() > 0 ? queue.storage[queue.rear - 1] : -1);
        break;
    }
  }

  return answer.join("\n");
}

console.log(solution(input));
