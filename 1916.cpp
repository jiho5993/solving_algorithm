#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

int n, m, st, en;
vector<vector<pii> > adj(1001);
int dist[1001];

void dij() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    fill(dist, dist+1001, 2e9);
    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i : adj[tmp]) {
            int nxt = i.first;
            int n_cost = i.second + cost;
            if(dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                pq.push({n_cost, nxt});
            }
        }
    }
    cout << dist[en];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 0, m) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1].pb({v2, cost});
    }
    cin >> st >> en;
    dij();

    return 0;
}