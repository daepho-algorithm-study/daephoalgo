const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line.trim());
}).on("close", () => {
  solution(input);
});

const solution = (input) => {
  let idx = 0;
  const T = Number(input[idx++]);

  for (let tc = 0; tc < T; tc++) {
    const N = Number(input[idx++]);
    const calc = (nums) => {
      let Csum = 0;
      let Gsum = 0;
      for (let num of nums) {
        const [C, G] = num;
        Csum += C;
        Gsum += C * G;
      }

      return [Csum, (Gsum / Csum).toFixed(1)];
    };
    const nums = [];
    for (let i = 0; i < N; i++) {
      const num = input[idx++].split(" ").map(Number);
      nums.push(num);
    }
    const answer = calc(nums);
    console.log(answer.join(" "));
  }
};
solution(input);
