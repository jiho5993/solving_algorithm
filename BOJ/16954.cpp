#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
string arr[9];
bool visit[9][9][9];

bool foo() {
    queue<tuple<int, int, int> > qt;
    qt.push({0, 7, 0});
    visit[0][7][0] = 1;
    while(!qt.empty()) {
        int t, y, x;
        tie(t, y, x) = qt.front();
        qt.pop();
        if(y == 0 && x == 7) return true;
        for(int i=0; i<9; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int tt = min(t+1, 8);
            if(xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;
            if(yy-t >= 0 && arr[yy-t][xx] == '#') continue;
            if(yy-t-1 >= 0 && arr[yy-t-1][xx] == '#') continue;
            if(visit[tt][yy][xx]) continue;
            visit[tt][yy][xx] = 1;
            qt.push({tt, yy, xx});
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    for(int i=0; i<8; i++) cin >> arr[i];
    cout << foo();

    return 0;
}