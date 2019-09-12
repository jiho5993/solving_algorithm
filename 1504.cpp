#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define INF 1e9
typedef pair<int, int> pii;

int n, e, node1, node2;
vector<pii> adj[801];

vector<int> dij(int st) {
    vector<int> dist(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({st, 0});
    dist[st] = 0;
    while(!pq.empty()) {
        int tmp = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i:adj[tmp]) {
            int nxt = i.first;
            int n_cost = i.second + cost;
            if(dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                pq.push({nxt, n_cost});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> e;
    fr(i, 0, e) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    cin >> node1 >> node2;

    vector<int> v1 = dij(1);
    vector<int> v2 = dij(node1);
    vector<int> v3 = dij(node2);

    int rs = min(v1[node1]+v2[node2]+v3[n], v1[node2]+v3[node1]+v2[n]);
    if(INF <= rs || rs < 0) cout << "-1";
    else cout << rs;

    return 0;
}