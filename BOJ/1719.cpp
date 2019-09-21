#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

int n, m;
int dist[201], backtrack[201];
vector<pii> adj[201];

void dij(int st) {
    fill(backtrack, backtrack+201, 0);
    fill(dist, dist+201, 2e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(st, 0));
    dist[st] = 0;
    while(!pq.empty()) {
        int tmp = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i : adj[tmp]) {
            int nxt = i.first;
            int n_cost = i.second+cost;
            if(dist[nxt] > n_cost) {
                backtrack[nxt] = tmp;
                dist[nxt] = n_cost;
                pq.push(mp(nxt, n_cost));
            }
        }
    }
    fr(i, 1, n+1) {
        if(i == st) {
            cout << "- ";
            continue;
        }
        stack<int> ss;
        for(int j=i; j!=st; j=backtrack[j]) ss.push(j);
        cout << ss.top() << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    fr(i, 1, n+1) dij(i);

    return 0;
}