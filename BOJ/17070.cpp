#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
int arr[17][17], dp[17][17][3];
const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};

int foo(int x, int y, int tmp) {
    if(x > N || y > N || arr[x][y]) return 0;
    if(tmp == 2 && (arr[x][y-1] || arr[x-1][y])) return 0;

    int &ret = dp[x][y][tmp];
    if(ret != -1) return ret;
    
    if(x == N && y == N) return 1;

    ret = 0;
    for(int i=0; i<3; i++) {
        if((tmp == 0 && i == 1) || (tmp == 1 && i == 0)) continue;
        ret += foo(x+dx[i], y+dy[i], i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> arr[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << foo(1, 2, 0);

    return 0;
}