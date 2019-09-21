#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int degree[32001], rs[32001];
vector<vector<int> > mat(32001);
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    fr(i, 0, m) {
        int a, b; cin >> a >> b;
        degree[b]++;
        mat[a].pb(b);
    }
    fr(i, 1, n+1)
        if(!degree[i])
            q.push(i);
    fr(i, 1, n+1) {
        int tmp = q.front();
        rs[i] = tmp;
        q.pop();
        fr(j, 0, mat[tmp].size()) {
            int idx = mat[tmp][j];
            if(!(--degree[idx]))
                q.push(idx);
        }
    }
    fr(i, 1, n+1) pt1(rs[i]);

    return 0;
}