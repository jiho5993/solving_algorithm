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

int n, k;
int visit[100001];
int go[3] = {2, -1, 1};

int bfs() {
    queue<pair<int, int> > qp;
    qp.push(mp(n, 0));
    visit[n] = 1;
    while(!qp.empty()) {
        int cur_idx = qp.front().first;
        int cur_time = qp.front().second;
        qp.pop();
        if(cur_idx == k) return cur_time;
        fr(i, 0, 3) {
            int next = (i != 0 ? cur_idx + go[i] : cur_idx * go[i]);
            if((0 <= next && next < 100001) && !visit[next]) {
                if(i != 0) {
                    qp.push(mp(next, cur_time+1));
                    visit[next] = 1;
                } else if(i == 0) {
                    qp.push(mp(next, cur_time));
                    visit[next] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> k;
    pt(bfs());

    return 0;
}