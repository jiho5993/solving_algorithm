#include <bits/stdc++.h>
using namespace std;

#define MAX 2187

int N, ret[3];
int arr[MAX+5][MAX+5];

void foo(int x, int y, int diff) {
    int val = arr[x+1][y+1];
    bool flag = false;
    for(int i=x+1; i<=x+diff; i++) {
        for(int j=y+1; j<=y+diff; j++) {
            if(val != arr[i][j]) {
                flag = true;
                break;
            }
        }
    }
    if(!flag) {
        ret[val+1]++;
        return;
    }
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            foo(x+(diff/3)*i, y+(diff/3)*j, diff/3);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> arr[i][j];
    foo(0, 0, N);
    cout << ret[0] << '\n' << ret[1] << '\n' << ret[2];

    return 0;
}