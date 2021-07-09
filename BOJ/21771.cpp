#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int R, C, cnt=0;
int sz[2][2];
string arr[101];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> R >> C;
    for(int i=0; i<4; i++) cin >> sz[i/2][i%2];
    for(int i=0; i<R; i++) {
        cin >> arr[i];
        for(int j=0; j<C; j++)
            if(arr[i][j] == 'P')
                cnt++;
    }
    sz[1][0]*sz[1][1] == cnt ? cout << 0 : cout << 1;

    return 0;
}