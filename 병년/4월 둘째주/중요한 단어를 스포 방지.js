const solution = (message, spoiler_ranges) => {
  const words = [];
  let i = 0;

  while (i < message.length) {
    while (i < message.length && message[i] === " ") i++;
    if (i >= message.length) break;

    const start = i;
    while (i < message.length && message[i] !== " ") i++;
    words.push({
      word: message.slice(start, i),
      start,
      end: i - 1,
    });
  }

  const isSpoiler = (word) => spoiler_ranges.some(([s, e]) => word.start <= e && word.end >= s);

  const nonSpolier = new Set();
  for (const w of words) {
    if (!isSpoiler(w)) {
      nonSpolier.add(w.word);
    }
  }

  const spoiler = words.filter(isSpoiler);

  let answer = 0;
  const seen = new Set();

  for (const w of spoiler) {
    if (nonSpolier.has(w.word)) continue;
    if (seen.has(w.word)) continue;

    seen.add(w.word);
    answer++;
  }

  return answer;
};
