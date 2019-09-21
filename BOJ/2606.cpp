#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

struct DisJointSet {
    vector<int> parent, rank;
    DisJointSet(int n) : parent(n), rank(n, 1) {
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    int find(int n) {
        if(n == parent[n])
            return n;
        return parent[n] = find(parent[n]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, cnt=0; cin >> n >> m;
    DisJointSet ds(n+1);
    while(m--) {
        int a, b; cin >> a >> b;
        ds.merge(a, b);
    }
    int node = ds.find(1);
    for(int i=1; i<=n; i++)
        if(ds.find(i) == node) cnt++;
    pt(cnt-1);

    return 0;
}