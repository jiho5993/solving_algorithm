#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

int V, E;
vector<pair<int, int> > adj[10001];
bool selected[10001];
int dist[10001];

int prim(int pn) {
    int ret = 0;
    for(int i=1; i<=pn; i++) dist[i] = INF;
    dist[1] = 0;
    for(int i=1; i<=pn; i++) {
        int now=-1, min_dist=INF;
        for(int j=1; j<=pn; j++) {
            if(!selected[j] && min_dist > dist[j]) {
                min_dist = dist[j];
                now = j;
            }
        }
        if(now < 0) return INF;
        ret += min_dist;
        selected[now] = 1;
        for(auto edge : adj[now]) dist[edge.first] = min(dist[edge.first], edge.second);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> V >> E;
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cout << prim(V);

    return 0;
}