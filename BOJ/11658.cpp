#include <bits/stdc++.h>
using namespace std;

int N, M, arr[1100][1100];
int tree[1100][1100];

int query(int y, int x) {
    int ret = 0;
    while(y > 0) {
        int j = x;
        while(j > 0) {
            ret += tree[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return ret;
}

void update(int y, int x, int diff) {
    while(y <= N) {
        int j = x;
        while(j <= N) {
            tree[y][j] += diff;
            j += (j & -j);
        }
        y += (y & -y);
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    while(M--) {
        int cmd; cin >> cmd;
        if(cmd == 0) {
            int a, b, c; cin >> a >> b >> c;
            int diff = c-arr[a][b];
            arr[a][b] = c;
            update(a, b, diff);
        } else {
            int a, b, c, d; cin >> a >> b >> c >> d;
            cout << query(c, d)-query(c, b-1)-query(a-1, d)+query(a-1, b-1) << '\n';
        }
    }

    return 0;
}