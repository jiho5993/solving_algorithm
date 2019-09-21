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

int degree[32001];
vector<int> mat[32001];
priority_queue<int, vector<int>, greater<int> > pq;

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
            pq.push(i);
    fr(i, 1, n+1) {
        int tmp = pq.top();
        pt1(tmp);
        pq.pop();
        for(auto j:mat[tmp])
            if(!(--degree[j]))
                pq.push(j);
    }

    return 0;
}