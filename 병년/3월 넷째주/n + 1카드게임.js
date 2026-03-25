const solution = (coins, cards) => {
  const n = Math.max(...cards);
  const stack = new Set(cards.slice(0, Math.floor(n / 3)));

  let head = n / 3;
  let round = 1;

  const case1 = () => {
    for (const card of Array.from(stack)) {
      const next = n + 1 - card;
      if (card !== next && stack.has(next)) {
        stack.delete(card);
        stack.delete(next);
        return true;
      }
    }
    return false;
  };

  const case2 = (a, b) => {
    const nextA = n + 1 - a;
    const nextB = n + 1 - b;

    if (stack.has(nextA)) {
      stack.delete(nextA);
      stack.add(b);
      return true;
    }
    if (stack.has(nextB)) {
      stack.delete(nextB);
      stack.add(a);
      return true;
    }
    return false;
  };

  const case3 = (a, b) => {
    if (a + b === n + 1) return true;

    const nextA = n + 1 - a;
    const nextB = n + 1 - b;

    for (let card of Array.from(stack)) {
      if (card === nextA) {
        stack.delete(card);
        stack.add(b);
        return true;
      }
      if (card === nextB) {
        stack.delete(card);
        stack.add(a);
        return true;
      }
    }
    return false;
  };
  while (head < cards.length) {
    const a = cards[head];
    const b = cards[head + 1];
    head += 2;
    if (a + b === n + 1) {
      round++;
      continue;
    }
    if (case1()) {
      round++;
    } else if (coins >= 1 && case2(a, b)) {
      coins--;
      round++;
    } else if (coins >= 2 && case3(a, b)) {
      coins -= 2;
      round++;
    } else {
      break;
    }
  }

  return round;
};
