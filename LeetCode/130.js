class MyQueue {
  idx = 0;
  arr = [];

  push(x) {
    this.arr.push(x);
  }

  pop() {
    return this.arr[this.idx++];
  }

  empty() {
    return this.arr.length === this.idx;
  }
}

const foo = (board, N, M, x, y) => {
  const dx = [1, -1, 0, 0];
  const dy = [0, 0, 1, -1];

  const res = [];
  for (let i=0; i<N; i++) {
    const s = [];
    for (let j=0; j<M; j++) s.push(board[i][j]);
    res.push(s);

    for (let j=0; j<M; j++) process.stdout.write(res[i][j] + " ");
    console.log();
  }
  const q = new MyQueue();

  q.push({x, y});
  res[x][y] = "X";

  while (!q.empty()) {
    const {x, y} = q.pop();

    for (let i=0; i<4; i++) {
      const nx = x + dx[i], ny = y + dy[i];

      if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
      if (res[nx][ny] !== "O") continue;

      if (nx === 0 || nx === N-1 || ny === 0 || ny === M-1) {
        return board;
      }

      res[nx][ny] = "X";
      q.push({
        x: nx,
        y: ny
      });
    }
  }

  return res;
}

/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
  const N = board.length, M = board[0].length;

  for (let i=0; i<N; i++) {
    for (let j=0; j<M; j++) {
      if ((1 <= i && i < N-1) && (1 <= j && j < M-1)) {
        if (board[i][j] === 'O') {
          const res = foo(board, N, M, i, j);
          
          for (let k=0; k<N; k++) {
            for (let l=0; l<M; l++) {
              board[k][l] = res[k][l];
            }
          }
        }
      }
    }
  }
};