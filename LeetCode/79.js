const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];

let flag = false;

const foo = (board, vis, word, N, M, x, y, sz) => {
  if (flag) return;

  if (sz === word.length) {
    flag = true;
    return;
  }
  else if (sz > word.length) {
    return;
  }

  for (let i=0; i<4; i++) {
    const nx = x + dx[i], ny = y + dy[i];

    if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
    if (vis[nx][ny] || board[nx][ny] !== word[sz]) continue;

    vis[nx][ny] = true;
    foo(board, vis, word, N, M, nx, ny, sz+1);
    vis[nx][ny] = false;
  }
};

/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  const N = board.length, M = board[0].length;
  flag = false;

  for (let i=0; i<N; i++) {
    for (let j=0; j<M; j++) {
      if (board[i][j] === word[0]) {
        const vis = new Array(N+1);
        for (let k=0; k<N+1; k++) {
          vis[k] = new Array(M+1);
          for (let l=0; l<M+1; l++) vis[k][l] = false;
        }

        vis[i][j] = true;
        foo(board, vis, word, N, M, i, j, 1);

        if (flag) return true;
        else continue;
      }
    }
  }

  return false;
};