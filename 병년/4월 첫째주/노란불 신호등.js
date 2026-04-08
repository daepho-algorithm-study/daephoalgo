const solution = (signals) => {
  let shin = signals.length;
  const gcd = (a, b) => (b === 0 ? a : gcd(b, a % b));
  const lcm = (a, b) => (a * b) / gcd(a, b);
  let len = signals.map(([g, y, r]) => g + y + r).reduce((a, b) => lcm(a, b));
  let count = Array(len).fill(0);
  for (let i = 0; i < signals.length; i++) {
    let green = signals[i][0];
    let yello = signals[i][1];
    let red = signals[i][2];

    let start = green + 1;
    let period = green + red + yello;
    let duration = yello;
    for (let j = 0; j < len; j++) {
      if (j >= start && (j - start) % period < duration) {
        count[j]++;
      }
    }
  }
  for (let i = 0; i < count.length; i++) {
    if (count[i] === shin) {
      return i;
    }
  }
  return -1;
};
