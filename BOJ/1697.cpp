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

int n, k, t;
int visit[100001];
int go[3] = {1, -1, 2};

void bfs() {
    queue<int> q;
    visit[n] = 1;
    q.push(n);
    while(!q.empty()) {
        int s = sz(q);
        fr(i, 0, s) {
            int x = q.front();
            q.pop();
            if(x == k) {
                pt(t);
                return;
            }
            fr(j, 0, 3) {
                int xx = (j == 2 ? x * go[j] : x + go[j]);
                if((0 <= xx && xx < 100001) && !visit[xx]) {
                    visit[xx] = 1;
                    q.push(xx);
                }
            }
        }
        t++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> k;
    bfs();

    return 0;
}