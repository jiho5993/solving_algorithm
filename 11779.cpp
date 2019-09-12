#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

int n, m, st, en;
int dist[1001], trace[1001];
vector<pii> adj[1001];

void dij() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, st});
    dist[st] = 0;
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
                trace[nxt] = tmp;
                pq.push({n_cost, nxt});
            }
        }
    }
    cout << dist[en] << '\n';
    int cnt=1;
    vector<int> v;
    for(int i=en; i!=st; i=trace[i]) {
        v.pb(i);
        cnt++;
    }
    v.pb(st);
    cout << cnt << '\n';
    for(int i=v.size()-1; i>=0; i--) cout << v[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    cin >> st >> en;
    fill(dist, dist+1001, 2e9);
    dij();

    return 0;
}