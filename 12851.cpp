#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[3] = {1, -1, 2};
int rs, cnt, arr[100001];

void bfs(int src, int dest) {
    queue<int> q;
    q.push(src);
    while(!cnt) {
        int ss = q.size();
        while(ss--) {
            int x = q.front();
            q.pop();
            if (x == dest) cnt++;
            fr(i, 0, 3) {
                int xx = (i == 2 ? x * dx[i] : x + dx[i]);
                if((0 <= xx && xx <= 1e5) && (!arr[xx] || arr[xx] == arr[x]+1)) {
                    q.push(xx);
                    arr[xx] = arr[x] + 1;
                }
            }
        }
        rs++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    bfs(n, m);
    cout << rs-1 << '\n' << cnt;

    return 0;
}