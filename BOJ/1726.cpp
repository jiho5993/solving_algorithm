#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int dx[] = {0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

struct info {
	int y, x, dir;
};

int N, M;
info st, en;
bool arr[101][101], visit[101][101][5];

int foo() {
	queue<pair<info, int> > qp;
	qp.push({st, 0});
	visit[st.y][st.x][st.dir] = 1;
	while(!qp.empty()) {
		info tmp = qp.front().first;
		int cnt = qp.front().second;
		qp.pop();
		if(tmp.y == en.y && tmp.x == en.x && tmp.dir == en.dir) return cnt;
		for(int i=1; i<=3; i++) {
			int yy = tmp.y + dy[tmp.dir]*i;
			int xx = tmp.x + dx[tmp.dir]*i;
			if(visit[yy][xx][tmp.dir]) continue;
			if((0 <= yy && yy < N) && (0 <= xx && xx < M) && !arr[yy][xx]) {
				qp.push({{yy, xx, tmp.dir}, cnt+1});
				visit[yy][xx][tmp.dir] = 1;
			} else break;
		}
		for(int i=1; i<=4; i++) {
			int dir = tmp.dir;
			if(dir == i || visit[tmp.y][tmp.x][i]) continue;
			visit[tmp.y][tmp.x][i] = 1;
			if((dir == 1 && i == 2) || (dir == 2 && i == 1) || (dir == 3 && i == 4) || (dir == 4 && i == 3)) qp.push({{tmp.y, tmp.x, i}, cnt+2});
			else qp.push({{tmp.y, tmp.x, i}, cnt+1});
		}
	}
	return -1;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
	int a, b, c; cin >> a >> b >> c;
	st = {a-1, b-1, c};
	cin >> a >> b >> c;
	en = {a-1, b-1, c};
	cout << foo();

    return 0;
}