const solution = (n) => {
  var answer = "";

  while (n > 0) {
    let num = n % 3;
    if (num === 1) {
      answer += "1";
    } else if (num === 2) {
      answer += "2";
    } else {
        // 나머지 값이 0인 경우에 자리수를 올리기 위해 n값을 하나 빼줌
        /**
         * ex n = 6
         * num = 0
         * answer += "4"
         * 이후에 n 값을 그대로 넘긴다면
         * n = n / 3 = 2
         * 다음 while 문에서 
         * n % 3 = 2
         * answer에 "24"가 들어가게 됨
         * 결국 아직 자리수가 올라가면 안되는 경우이기 때문에 
         * n 값에서 1을 빼줘서 보정을 해줌
         */
      answer += "4";
      n--;
    }

    n = Math.floor(n / 3);
  }

  return answer.split("").reverse().join("");
};
