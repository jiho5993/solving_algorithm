#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int res = 0;
bool visit[5][5];
map<int, pair<int, int> > m;

int chk() {
    int ret = 0;
    int _3=0, _4=0;
    for(int i=0; i<5; i++) {
        int _1=0, _2=0;
        _3 += visit[i][i];
        _4 += visit[i][4-i];
        for(int j=0; j<5; j++) _1 += visit[i][j];
        for(int j=0; j<5; j++) _2 += visit[j][i];
        if(_1 == 5) ret++;
        if(_2 == 5) ret++;
    }
    if(_3 == 5) ret++;
    if(_4 == 5) ret++;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    for(int i=0; i<25; i++) {
        int a; cin >> a;
        m[a] = {i/5, i%5};
    }
    for(int i=1; i<=25; i++) {
        int a; cin >> a;
        visit[m[a].X][m[a].Y] = 1;
        if(chk() > 2) {
            res = i;
            break;
        }
    }
    cout << res;

    return 0;
}