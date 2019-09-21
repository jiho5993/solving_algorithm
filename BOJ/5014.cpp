#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int F, S, G, U, D;
int visit[1000001];

int bfs(int go[2]) {
    queue<int> q;
    q.push(S);
    visit[S] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == G) return visit[cur]-1;
        fr(j, 0, 2) {
            int next = cur + go[j];
            if ((0 < next && next <= F) && !visit[next]) {
                visit[next] = visit[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> F >> S >> G >> U >> D;
    int go[2] = {U, -D};
    int rs = bfs(go);
    rs != -1 ? pt(rs) : pt("use the stairs");

    return 0;
}