const solution = (n, lost, reserve) => {
  const realLost = lost.filter((l) => !reserve.includes(l));
  const realReserve = reserve.filter((r) => !lost.includes(r));

  realLost.sort((a, b) => a - b);
  realReserve.sort((a, b) => a - b);

  let answer = n - realLost.length;

  for (let i = 0; i < realReserve.length; i++) {
    for (let j = 0; j < realLost.length; j++) {
      if (realLost[j] === realReserve[i] - 1 || realLost[j]=== realReserve[i] + 1) {
        answer++;
        realLost[j] = -1;
        break;
      }
    }
  }

  return answer;
};
