#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N;
double arr[4], res;
bool visit[31][31];

void foo(int y, int x, int cnt, double p) {
    if(cnt == N) {
        res += p;
        return;
    }
    visit[y][x] = 1;
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(!visit[yy][xx]) foo(yy, xx, cnt+1, p*arr[i]);
    }
    visit[y][x] = 0;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<4; i++) {
        cin >> arr[i];
        arr[i] *= 0.01;
    }
    foo(15, 15, 0, 1);
    cout << fixed;
    cout.precision(10);
    cout << res;

    return 0;
}