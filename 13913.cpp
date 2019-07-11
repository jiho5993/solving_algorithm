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

struct dt {
    int pos, time;
    dt(int p, int t) {
        pos = p;
        time = t;
    }
};

int n, k;
int visit[100001], back[100001];
int go[3] = {2, -1, 1};

void bfs() {
    queue<dt> qp;
    qp.push(dt(n, 0));
    back[n] = -1;
    visit[n] = 1;
    while(!qp.empty()) {
        int cur_idx = qp.front().pos;
        int cur_time = qp.front().time;
        qp.pop();
        if(cur_idx == k) {
            pt(cur_time);
            vector<int> v;
            for(int i=cur_idx; i!=-1; i=back[i]) v.pb(i);
            reverse(all(v));
            fr(i, 0, sz(v)) pt1(v[i]);
            return;
        }
        fr(i, 0, 3) {
            int next = (i != 0 ? cur_idx + go[i] : cur_idx * go[i]);
            if((0 <= next && next < 100001) && !visit[next]) {
                back[next] = cur_idx;
                qp.push(dt(next, cur_time + 1));
                visit[next] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> k;
    bfs();

    return 0;
}