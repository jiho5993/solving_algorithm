#include <bits/stdc++.h>
using namespace std;

int N, z_cnt, o_cnt;
bool arr[129][129];

void foo(int x, int y, int diff) {
    bool f = arr[x][y], flag = true;
    for(int i=x; i<x+diff; i++) {
        for(int j=y; j<y+diff; j++) {
            if(f != arr[i][j]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(!flag) {
        int v = diff/2;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                foo(x+(v*i), y+(v*j), v);
    } else {
        if(f) o_cnt++;
        else z_cnt++;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];
    foo(0, 0, N);
    cout << z_cnt << '\n' << o_cnt;

    return 0;
}