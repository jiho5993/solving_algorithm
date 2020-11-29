#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N, M, res=100;
int arr[9][9];
vii v;

void move(int dir, int y, int x) {
    switch(dir) {
        case 0: // n
            for(int i=y-1; i>=0; i--) {
                if(arr[i][x] == 6) break;
                if(arr[i][x] == 0) arr[i][x] = -1;
            }
            break;
        case 1: // e
            for(int j=x+1; j<M; j++) {
                if(arr[y][j] == 6) break;
                if(arr[y][j] == 0) arr[y][j] = -1;
            }
            break;
        case 2: // s
            for(int i=y+1; i<N; i++) {
                if(arr[i][x] == 6) break;
                if(arr[i][x] == 0) arr[i][x] = -1;
            }
            break;
        case 3: // w
            for(int j=x-1; j>=0; j--) {
                if(arr[y][j] == 6) break;
                if(arr[y][j] == 0) arr[y][j] = -1;
            }
            break;
    }
}

void foo(int idx) {
    if(idx == v.size()) {
        int cnt=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!arr[i][j])
                    cnt++;
            }
        }
        res = min(res, cnt);
        return;
    }
    int y = v[idx].first, x = v[idx].second;
    int cctv = arr[y][x];
    int cpy_arr[9][9];
    memcpy(cpy_arr, arr, sizeof(arr));
    switch(cctv) {
        case 1:
            for(int i=0; i<4; i++) {
                move(i, y, x);
                foo(idx+1);
                memcpy(arr, cpy_arr, sizeof(cpy_arr));
            }
            break;
        case 2:
            for(int i=0; i<2; i++) {
                move(i, y, x);
                move(i+2, y, x);
                foo(idx+1);
                memcpy(arr, cpy_arr, sizeof(cpy_arr));
            }
            break;
        case 3:
            for(int i=0; i<4; i++) {
                move(i, y, x);
                move((i+1)%4, y, x);
                foo(idx+1);
                memcpy(arr, cpy_arr, sizeof(cpy_arr));
            }
            break;
        case 4:
            for(int i=0; i<4; i++) {
                move(i, y, x);
                move((i+1)%4, y, x);
                move((i+2)%4, y, x);
                foo(idx+1);
                memcpy(arr, cpy_arr, sizeof(cpy_arr));
            }
            break;
        case 5:
            for(int i=0; i<4; i++) move(i, y, x);
            foo(idx+1);
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6) v.pb({i, j});
        }
    }
    foo(0);
    cout << res;

    return 0;
}