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

int n, m, k, minCost=0;
int cost[10001], p[10001];

int find(int n) {
    if(p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(cost[u] > cost[v]) p[u] = v;
    else p[v] = u;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    fill(p, p+10001, -1);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> cost[i];
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }
    for(int i=1; i<=n; i++)
        if(p[i] == -1)
            minCost += cost[i];
    if(k < minCost) pt("Oh no");
    else pt(minCost);

    return 0;
}