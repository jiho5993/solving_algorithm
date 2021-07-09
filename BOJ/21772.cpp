#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int R, C, T, res=0;
string arr[101];

void foo(int y, int x, int goguma, int t) {
    if(t == T) {
        res = max(res, goguma);
        return;
    }
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if((0 <= xx && xx < C) && (0 <= yy && yy < R) && arr[yy][xx] != '#') {
            bool flag = false;
            if(arr[yy][xx] == 'S') {
                arr[yy][xx] = '.';
                flag = true;
            }
            foo(yy, xx, goguma+flag, t+1);
            if(flag) arr[yy][xx] = 'S';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> R >> C >> T;
    int a, b;
    for(int i=0; i<R; i++) {
        cin >> arr[i];
        for(int j=0; j<C; j++) {
            if(arr[i][j] == 'G') {
                a = i;
                b = j;
            }
        }
    }

    foo(a, b, 0, 0);
    cout << res;

    return 0;
}