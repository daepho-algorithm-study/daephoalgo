const solution = (servery, choices) => {
  const obj = {
    A: 0,
    N: 0,
    C: 0,
    F: 0,
    J: 0,
    M: 0,
    R: 0,
    T: 0,
  };
  for (let i = 0; i < choices.length; i++) {
    let choice = choices[i];
    const [f, b] = servery[i].split("");
    if (0 < choice && choice < 4) {
      obj[f] += 4 - choice;
    } else if (4 < choice && choice < 8) {
      obj[b] += choice - 4;
    }
  }
  const types = ["RT", "CF", "JM", "AN"];
  let result = "";
  for (let type of types) {
    const [a, b] = type;

    if (obj[a] >= obj[b]) {
      result += a;
    } else {
      result += b;
    }
  }
  return result;
};
