#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

vector<pii> adj[50001];
vector<int> res(50001, -1);
bool is_summit[50001];

vector<int> dij(vector<int> gates) {
    int top = 1e9, it = 1e9;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    for (auto g: gates) {
        pq.push({0, g});
        res[g] = 0;
    }

    while (!pq.empty()) {
        int s = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (res[x] < s) continue;
        if (is_summit[x]) {
            if (it == s) top = min(top, x);
            else if (it > s) {
                it = s;
                top = x;
            }
            continue;
        }

        for (auto n: adj[x]) {
            int ns = max(s, n.second);
            if (res[n.first] == -1 || res[n.first] > ns) {
                res[n.first] = ns;
                pq.push({ns, n.first});
            }
        }
    }

    return {top, it};
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto i: paths) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    for (int s: summits) is_summit[s] = true;

    return dij(gates);
}
