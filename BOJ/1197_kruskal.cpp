#include <bits/stdc++.h>
using namespace std;

struct ver {
    int st, en, weight;
};

bool cmp(ver a, ver b) {return a.weight < b.weight;}

int V, E;
int parent[10001];
vector<ver> adj;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

int kruskal() {
    int ret = 0;
    for(auto tmp : adj) {
        int st = tmp.st, en = tmp.en;
        int w = tmp.weight;
        if(find(st) == find(en)) continue;
        merge(st, en);
        ret += w;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> V >> E;
    for(int i=0; i<=V; i++) parent[i] = i;
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        adj.push_back({a, b, c});
    }
    sort(adj.begin(), adj.end(), cmp);
    cout << kruskal();

    return 0;
}