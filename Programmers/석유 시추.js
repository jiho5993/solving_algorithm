const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];
let N, M;
const visited = Array.from(new Array(501), () => new Array(501).fill(false));
const cnt_arr = new Array(501).fill(0);

function bfs(arr, x, y) {
  const queue = [[x, y]];
  visited[x][y] = true;

  let cnt = 1;
  const pos = new Set([y]);
  while (queue.length) {
    const [x, y] = queue.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
      if (arr[nx][ny] !== 1 || visited[nx][ny]) continue;
      queue.push([nx, ny]);
      visited[nx][ny] = true;
      cnt++;
      pos.add(ny);
    }
  }

  pos.forEach((p) => (cnt_arr[p] += cnt));
}

function solution(land) {
  N = land.length;
  M = land[0].length;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (land[i][j] === 1 && !visited[i][j]) {
        bfs(land, i, j);
      }
    }
  }

  return Math.max(...cnt_arr);
}

const testCases = [
  [
    [
      [0, 0, 0, 1, 1, 1, 0, 0],
      [0, 0, 0, 0, 1, 1, 0, 0],
      [1, 1, 0, 0, 0, 1, 1, 0],
      [1, 1, 1, 0, 0, 0, 0, 0],
      [1, 1, 1, 0, 0, 0, 1, 1],
    ],
  ],
  [
    [
      [1, 0, 1, 0, 1, 1],
      [1, 0, 1, 0, 0, 0],
      [1, 0, 1, 0, 0, 1],
      [1, 0, 0, 1, 0, 0],
      [1, 0, 0, 1, 0, 1],
      [1, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1],
    ],
  ],
];

testCases.forEach((testCase) => {
  console.log(solution(...testCase));
});

