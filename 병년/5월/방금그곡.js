const solution = (m, musicinfos) => {
  let answer = "";
  let maxTime = -1;
  /**
   * # 처리
   */
  const convert = (str) => {
    return str
      .replaceAll("C#", "c")
      .replaceAll("D#", "d")
      .replaceAll("F#", "f")
      .replaceAll("G#", "g")
      .replaceAll("A#", "a")
      .replaceAll("B#", "b")
      .replaceAll("E#", "e");
  };
  m = convert(m);
  /**
   * 1. 음악 재생 시간 구하기
   * */
  const calc = (start, end) => {
    const [startHour, startMin] = start.split(":").map(Number);
    const [endHour, endMin] = end.split(":").map(Number);
    let result = 0;
    // 만약 시작 시간과 끝 시간이 똑같다면 분 단위로 빼서 리턴
    if (startHour === endHour) {
      result = endMin - startMin;
    } else {
      const t1 = startHour * 60 + startMin;
      const t2 = endHour * 60 + endMin;

      result = Math.abs(t2 - t1);
    }
    return result;
  };
  /**
   * 2. MusicInfos 에서 찾기
   */
  for (let music of musicinfos) {
    let [starTime, endTime, title, code] = music.split(",");
    code = convert(code);
    let timeDiff = calc(starTime, endTime);
    let cnt = Math.ceil(timeDiff / code.length);

    const str = code.repeat(cnt).slice(0, timeDiff);
    for (let i = 0; i <= str.length - m.length; i++) {
      let diff = str[i];
      for (let j = 1; j < m.length; j++) {
        diff += str[i + j];
      }
      if (diff === m) {
        if (timeDiff > maxTime) {
          answer = title;
          maxTime = timeDiff;
        }
        break;
      }
    }
  }
  return answer || "(None)";
};
