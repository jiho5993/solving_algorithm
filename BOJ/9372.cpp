#include <bits/stdc++.h>
using namespace std;

#define INF INT32_MAX
typedef pair<int, int> pii;

int V, E;
bool selected[1001];
vector<pii> adj[1001];
priority_queue<pii, vector<pii>, greater<pii> > dist;

int prim(int pn) {
    int ret = 0;
    dist.push({0, 1});
    for(int i=1; i<=pn; i++) {
        int now=-1, min_dist = INF;
        while(!dist.empty()) {
            now = dist.top().second;
            if(!selected[now]) {
                min_dist = dist.top().first;
                break;
            }
            dist.pop();
        }
        if(min_dist == INF) return INF;
        ret += min_dist;
        selected[now] = 1;
        for(auto edge : adj[now]) dist.push(edge);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        fill(selected, selected+1001, false);
        while(!dist.empty()) dist.pop();
        for(int i=0; i<1001; i++) adj[i].clear();
        cin >> V >> E;
        while(E--) {
            int a, b; cin >> a >> b;
            adj[a].push_back({1, b});
            adj[b].push_back({1, a});
        }
        cout << prim(V) << '\n';
    }

    return 0;
}