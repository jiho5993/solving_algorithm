#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, del;
vector<int> arr[51];
vector<int> roots;
bool visited[51];

int bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = true;

    int res = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        bool flag = false;
        for (auto n: arr[x]) {
            if (visited[n]) continue;
            visited[n] = true;
            q.push(n);
            flag = true;
        }
        if (!flag) res++;
    }

    return res;
}

void solve() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        if (a == -1) roots.push_back(i);
        else arr[a].push_back(i);
    }

    cin >> del;
    visited[del] = true;

    int res = 0;
    for (int n: roots) {
        if (n == del) continue;
        res += bfs(n);
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
