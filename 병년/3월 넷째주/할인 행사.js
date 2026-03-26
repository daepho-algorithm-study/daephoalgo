const solution = (want, number, discount) => {
  const wants = {};
  let answer = 0;
  for (let i = 0; i < want.length; i++) {
    wants[want[i]] = number[i];
  }

  for (let i = 0; i <= discount.length; i++) {
    const window = discount.slice(i, i + 10);

    const windowMap = {};
    for (const item of window) {
      windowMap[item] = (windowMap[item] || 0) + 1;
    }

    let flag = true;

    for (const key of want) {
      if (windowMap[key] !== wants[key]) {
        flag = false;
        break;
      }
    }
    if (flag) answer++;
  }
  return answer;
};
