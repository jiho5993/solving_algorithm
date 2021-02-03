#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int N, M;
char arr[51][51];
bool visit[51][51];

bool foo(int y, int x, int py, int px, char tmp) {
    if(visit[y][x]) return true;
    visit[y][x] = true;
    bool flag = false;
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(yy < 0 || xx < 0 || yy >= N || xx >= M) continue;
        if(py == yy && px == xx) continue;
        if(tmp != arr[yy][xx]) continue;
        flag += foo(yy, xx, y, x, tmp);
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visit[i][j]) continue;
            if(foo(i, j, -1, -1, arr[i][j])) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}