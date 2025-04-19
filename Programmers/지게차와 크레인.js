String.prototype.replaceAt = function (index, char) {
  arr = this.split('');
  arr[index] = char;
  return arr.join('');
};

const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];
let N, M;

function bfs(storage, target) {
  const new_storage = Array.from(storage);
  let ret = 0;

  const queue = [[0, 0]];
  const visited = Array.from(new Array(N), () => new Array(M).fill(false));
  visited[0][0] = true;

  while (queue.length) {
    const [x, y] = queue.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
      if (visited[nx][ny]) continue;
      if (storage[nx][ny] === target) {
        new_storage[nx] = new_storage[nx].replaceAt(ny, '0');
        visited[nx][ny] = true;
        ret++;
        continue;
      }
      if (storage[nx][ny] === '0') {
        queue.push([nx, ny]);
        visited[nx][ny] = true;
      }
    }
  }

  return [new_storage, ret];
}

function all_del(storage, target) {
  let ret = 0;

  storage = storage.map((s) => {
    let res = '';
    for (let i = 0; i < s.length; i++) {
      if (s[i] === target) {
        res += '0';
        ret++;
      } else res += s[i];
    }
    return res;
  });

  return [storage, ret];
}

function solution(storage, requests) {
  N = storage.length + 2;
  M = storage[0].length + 2;
  var answer = (N - 2) * (M - 2);

  storage = storage.map((s) => '0' + s + '0');
  storage.unshift('0'.repeat(M));
  storage.push('0'.repeat(M));

  requests.forEach((r) => {
    if (r.length == 1) {
      const [s, del] = bfs(storage, r);
      storage = s;
      answer -= del;
    } else {
      const [s, del] = all_del(storage, r[0]);
      storage = s;
      answer -= del;
    }
  });

  return answer;
}

const testCases = [
  [
    ['AZWQY', 'CAABX', 'BBDDA', 'ACACA'],
    ['A', 'BB', 'A'],
  ],
  [
    ['HAH', 'HBH', 'HHH', 'HAH', 'HBH'],
    ['C', 'B', 'B', 'B', 'B', 'H'],
  ],
];

testCases.forEach((testCase) => {
  console.log(solution(...testCase));
});

