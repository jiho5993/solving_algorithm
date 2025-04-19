function solution(players, m, k) {
  let answer = 0;

  const queue = [];

  players.forEach((p, t) => {
    while (queue.length > 0 && queue[0] <= t) {
      queue.shift();
    }

    while (p >= (queue.length + 1) * m) {
      queue.push(t + k);
      answer++;
    }
  });

  return answer;
}

const testCases = [
  [[0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5], 3, 5],
  [[0, 0, 0, 10, 0, 12, 0, 15, 0, 1, 0, 1, 0, 0, 0, 5, 0, 0, 11, 0, 8, 0, 0, 0], 5, 1],
  [[0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 5, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1], 1, 1],
];

testCases.forEach((testCase) => {
  console.log(solution(...testCase));
});

