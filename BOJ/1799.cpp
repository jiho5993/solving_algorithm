#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
int N, ret[2];
bool arr[11][11], isused[2][11][11];

bool chk_line(bool c, int x, int y) {
    if(!arr[x][y]) return false;
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        for(int j=0; j<N; j++) {
            if((0 <= xx && xx < N) && (0 <= yy && yy < N)) {
                if(isused[c][xx][yy]) return false;
                xx += dx[i];
                yy += dy[i];
            }
        }
    }
    return true;
}

void foo(int x, int y, int ss, bool c) {
    ret[c] = max(ret[c], ss);
    if(y > N) {
        x += 1;
        y = !c ? ((x%2 == 0) ? 0 : 1) : ((x%2 == 0) ? 1 : 0);
    }
    if(x > N) return;
    if(chk_line(c, x, y)) {
        isused[c][x][y] = 1;
        foo(x, y+2, ss+1, c);
        isused[c][x][y] = 0;
    }
    foo(x, y+2, ss, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];
    foo(0, 0, 0, 0);
    foo(0, 1, 0, 1);
    cout << ret[0]+ret[1];

    return 0;
}