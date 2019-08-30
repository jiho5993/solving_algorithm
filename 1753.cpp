#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2e9;
const int MOD = 1000000007;

vector<vector<pii> > adj(20001);
int v, e, st;
int dist[20001];

void dij(int src) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    fill(dist, dist+20001, INF);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(auto i : adj[here]) {
            int there = i.first;
            int new_cost = i.second + cost;
            if(dist[there] > new_cost) {
                dist[there]  = new_cost;
                pq.push({new_cost, there});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> v >> e >> st;
    fr(i, 0, e) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1].pb({v2, cost});
    }
    dij(st);
    fr(i, 1, v+1) {
        if(dist[i] == INF) pt("INF");
        else pt(dist[i]);
    }

    return 0;
}