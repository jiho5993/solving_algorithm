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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string st, en="123456780";

int bfs() {
    queue<pair<string, int>> qp;
    unordered_set<string> visited;

    qp.push({st, 0});
    visited.insert(st);

    while (!qp.empty()) {
        string cur = qp.front().first;
        int cnt = qp.front().second;
        qp.pop();

        if (cur == en) return cnt;

        int pos = cur.find('0');
        int x = pos/3, y = pos%3;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= 3 || 0 > ny || ny >= 3) continue;

            string n = cur;
            swap(n[nx*3+ny], n[x*3+y]);

            if (visited.find(n) != visited.end()) continue;

            visited.insert(n);
            qp.push({n, cnt+1});
        }
    }

    return -1;
}

void solve() {
    for (int i=0; i<9; i++) {
        int a; cin >> a;
        st += a+'0';
    }

    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
