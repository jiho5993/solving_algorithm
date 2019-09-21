#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
vector<pii> adj[101];
int n, m, dist[101];

void dij(int st) {
    fill(dist, dist+n+1, 2e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({st, 0});
    dist[st] = 0;
    while(!pq.empty()) {
        int tmp = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i : adj[tmp]) {
            int nxt = i.first;
            int n_cost = i.second + cost;
            if(dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                pq.push({nxt, n_cost});
            }
        }
    }
    fr(i, 1, n+1) {
        if(dist[i] == 2e9) cout << "0 ";
        else cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    fr(i, 1, n+1) dij(i);

    return 0;
}