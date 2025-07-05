#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M, K;
vector<int> arr[5005];
bool stop[5005];

void solve() {
    cin >> N >> M >> K;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i=0; i<K; i++) {
        int a; cin >> a;
        stop[a] = true;
    }

    queue<int> q;
    unordered_set<int> visited;
    q.push(1);
    visited.insert(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto i: arr[cur]) {
            if (stop[i]) continue;
            if (visited.find(i) != visited.end()) continue;
            q.push(i);
            visited.insert(i);
        }
    }

    cout << visited.size()-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
