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
  const [N, S] = input[0].split(" ");
  // 1. 영어 중복 제거 및 카운트
  const case1 = (str) => {
    const set = new Set();
    for (let i = 0; i < str.length; i++) {
      set.add(str[i]);
    }
    let cnt = str.length - set.size;
    return [[...set].join(""), cnt];
  };

  let [str, cnt] = case1(S);
  // 2. 버려진 문자의 총 개수의 4개를 더한 값 붙이기
  const case2 = (str, cnt) => {
    let back = 4 + cnt;
    let newstr = str + back.toString();
    return newstr;
  };
  let current = case2(str, cnt);
  // 3. 등록 번호 붙이기
  const case3 = (str) => {
    let front = Number(N) + 1906;
    let newstr = front.toString() + str;
    return newstr;
  };
  let next = case3(current);

  // 4. 뒤집기
  let reverse = next.split("").reverse().join("");
  // 5. 문자열 붙이기
  let result = "smupc_" + reverse;
  console.log(result);
};
solution(input);
