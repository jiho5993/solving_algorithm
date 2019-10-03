#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[10][10];
vector<pair<int, int> > zero;

bool chk_line1(int y, int n) {
    for(int i=0; i<9; i++)
        if(arr[i][y] == n)
            return false;
    return true;
}

bool chk_line2(int x, int n) {
    for(int i=0; i<9; i++)
        if(arr[x][i] == n)
            return false;
    return true;
}

bool chk_box(int x, int y, int n) {
    x /= 3, y /= 3;
    for(int i=x*3; i<(x*3)+3; i++)
        for(int j=y*3; j<(y*3)+3; j++)
            if(arr[i][j] == n)
                return false;
    return true;
}

void dfs(int ss) {
    if(ss == zero.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) cout << arr[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }
    for(int val=1; val<10; val++) {
        int nx = zero[ss].first;
        int ny = zero[ss].second;
        if(chk_line1(ny, val) && chk_line2(nx, val) && chk_box(nx, ny, val)) {
            arr[nx][ny] = val;
            dfs(ss+1);
            arr[nx][ny] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                zero.pb({i, j});
        }
    }
    for(int val=1; val<10; val++) {
        int nx = zero[0].first;
        int ny = zero[0].second;
        if(chk_line1(ny, val) && chk_line2(nx, val) && chk_box(nx, ny, val)) {
            arr[nx][ny] = val;
            dfs(1);
            arr[nx][ny] = 0;
        }
    }

    return 0;
}