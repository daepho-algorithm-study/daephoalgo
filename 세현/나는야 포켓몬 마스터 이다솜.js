/*
--- JS Map method ---
new Map();                      선언
set(key, value)	                추가 / 수정
get(key)	                    값 조회
has(key)	                    존재 여부 확인
delete(key)	                    제거
clear()	                        모두 제거
size	                        요소 개수
forEach()	                    순회
keys(), values(), entries()	    ['key'만/'값'만/쌍 모두] 배열 반환
*/

const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
//   .map((e) => Number(e));
  //.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const fst_line = input[0].split(" ").map(Number)
  const N = fst_line[0]

  const numdic = new Map(input.slice(1, N+1).map((value, index) => [String(index+1), value.trim()]));
  const namedic = new Map(input.slice(1, N+1).map((value, index) => [value.trim(), String(index+1)]));
  const check = input.slice(N+1);
  const answer = []
  
  check.forEach((e) => {
    const pocketmon = numdic.has(e.trim()) ? numdic.get(e.trim()) : namedic.get(e.trim());
    answer.push(pocketmon)
  })

  return answer;
}

console.log(solution(input).join('\n'));
