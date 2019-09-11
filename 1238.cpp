#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[1001];
int n, m, x, rs=-1;

vector<int> dij(int st) {
    vector<int> dist(n+1, 2e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[st] = 0;
    pq.push(make_pair(0, st));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i : adj[tmp]) {
            int nxt = i.first;
            int n_cost = cost + i.second;
            if(n_cost < dist[nxt]) {
                dist[nxt] = n_cost;
                pq.push(make_pair(n_cost, nxt));
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    vector<int> back = dij(x);
    for(int i=1; i<=n; i++) {
        vector<int> go = dij(i);
        int tmp = go[x]+back[i];
        if(2e9 <= tmp || tmp < 0) continue;
        rs = max(rs, tmp);
    }
    cout << rs;

    return 0;
}