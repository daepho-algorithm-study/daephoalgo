function solution(book_time) {
  var answer = 0;

  book_time.sort();
  console.log(book_time);

  const room = [];
  const getTime = (str) => {
    let [hour, minuate] = str.split(":");

    return Number(hour) * 60 + Number(minuate);
  };

  for (let book of book_time) {
    const [start, end] = book;
    let startTime = getTime(start);
    let endTime = getTime(end) + 10;

    const idx = room.findIndex((v) => v <= startTime);

    if (idx === -1) room.push(endTime);
    else room[idx] = endTime;
  }

  return room.length;
}
