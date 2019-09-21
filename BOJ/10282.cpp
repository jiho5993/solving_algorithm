#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, d, c, dist[100001];
vector<vector<pii> > adj;

void dij() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<bool> visit(n+1, false);
    int rs_comp=0, rs_time=0;
    dist[c] = 0;
    pq.push(make_pair(0, c));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        visit[tmp] = true;
        rs_comp++;
        if(cost > rs_time) rs_time = cost;
        for(auto i : adj[tmp]) {
            int nxt = i.first;
            int n_cost = i.second + cost;
            if(!visit[nxt]) {
                if(dist[nxt] > n_cost) {
                    dist[nxt] = n_cost;
                    pq.push(make_pair(n_cost, nxt));
                }
            }
        }
    }
    cout << rs_comp << ' ' << rs_time << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> d >> c;
        fill(dist, dist+100001, 2e9);
        adj.clear();
        adj.resize(n+1);
        for(int i=0; i<d; i++) {
            int a, b, s; cin >> a >> b >> s;
            adj[b].push_back(make_pair(a, s));
        }
        dij();
    }

    return 0;
}