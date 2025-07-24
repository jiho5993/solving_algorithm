#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

vector<int> arr[101];
bool visited[101][101];

void bfs(int st) {
    queue<int> q;
    q.push(st);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i: arr[x]) {
            if (visited[st][i]) continue;
            visited[st][i] = true;
            q.push(i);
        }
    }
}

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a; cin >> a;
            if (a == 1) arr[i].push_back(j);
        }
    }
    for (int i=0; i<N; i++) {
        for (int x: arr[i]) {
            if (visited[i][x]) continue;
            bfs(i);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cout << visited[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
