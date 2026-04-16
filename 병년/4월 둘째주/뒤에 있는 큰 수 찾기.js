const solution = (numbers) => {
  const result = Array(numbers.length).fill(-1);
  const stack = []
  for (let i = 0; i < numbers.length; i++) {
    while(stack.length && numbers[stack[stack.length - 1]] < numbers[i]) {
        const idx = stack.pop()
        result[idx] = numbers[i]
    }
    stack.push(i)
  }
  return result
};
