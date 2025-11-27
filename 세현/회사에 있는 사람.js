/*
--- JS Set Methods ---
new Set();      set 선언
add(value)	    값 추가	    s.add(4);        // Set {1,2,3,4}
delete(value)	값 제거	    s.delete(2);     // Set {1,3,4}
has(value)	값 존재 	    s.has(3);        // true
clear()	모든 요소 제거	     s.clear();       // Set {}
size	요소 개수	         s.size;         // 3
*/

const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const n = Number(input[0])
  const people = input.slice(1).map((line) => line.split(" "));
  const workplace = new Set();
  people.forEach(([person, action]) => {
    if (action.trim() === 'enter') {
        workplace.add(person);
    } else if (action.trim() === 'leave') {
        workplace.delete(person);
    }
  })
  const answer = [...workplace].sort().reverse();

  return answer;
}

console.log(solution(input).join('\n'));
