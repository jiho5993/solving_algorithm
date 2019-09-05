#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n, h1, h2, m;
int arr[101][101], d[101];
bool visit[101];

void bfs(int st) {
    queue<int> q;
    visit[st] = 1;
    q.push(st);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        fr(i, 1, n+1) {
            if(arr[tmp][i] && !visit[i]) {
                visit[i] = 1;
                d[i] = d[tmp]+1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> h1 >> h2 >> m;
    fr(i, 0, m) {
        int x, y; cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }
    bfs(h1);
    d[h2] != 0 ? cout << d[h2] : cout << "-1";

    return 0;
}