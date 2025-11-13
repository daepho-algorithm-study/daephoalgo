const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [N, C] = input[0].split(" ").map(Number);
  const arr = [];
  for (let i = 1; i <= N; i++) {
    arr.push(Number(input[i]));
  }
  arr.sort((a, b) => a - b);
  let result = 0;

  const bis = () => {
    // Left
    let left = 0;
    // right
    let right = arr[arr.length - 1] - arr[0];
    
    // 이분 탐색
    while (left <= right) {
      let mid = Math.floor((right + left) / 2);
      let last = arr[0];
      let cnt = 1
      for (let i = 1; i < arr.length; i++) {
        if (arr[i] - last >= mid){
            cnt++
            last = arr[i]
        }
      }
      
      // 만약 C 개수와 크거나 같게 공유기 설치를 더 할 수 있으면
      if (cnt >= C) {
        // 결과값 갱신
        result = mid;
        // 계속 늘려서 탐색 해보기
        left = mid + 1;
      } else {
        // 줄여서 탐색 해보기
        right = mid - 1;
      }
    }
  };
  bis();
  console.log(result);
};
solution(input);
