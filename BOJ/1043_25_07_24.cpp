#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
int arr[51], party[51][51];
bool res[51];
vector<int> adj[51];

void bfs(int st) {
    queue<int> q;
    bool visited[51] = {0,};

    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        int x = q.front();
        res[x] = true;
        q.pop();

        for (int n: adj[x]) {
            if (visited[n]) continue;
            visited[n] = true;
            q.push(n);
        }
    }
}

void solve() {
    cin >> N >> M;
    int K; cin >> K;
    for (int i=0; i<K; i++) cin >> arr[i];

    for (int i=0; i<M; i++) {
        int a; cin >> a;
        for (int j=0; j<a; j++) cin >> party[i][j];
        if (a >= 2) {
            for (int j=1; j<a; j++) {
                adj[party[i][j-1]].push_back(party[i][j]);
                adj[party[i][j]].push_back(party[i][j-1]);
            }
        }
    }

    for (int i=0; i<K; i++) bfs(arr[i]);

    int cnt = 0;
    for (int i=0; i<M; i++) {
        bool flag = false;
        for (int j=0; j<51; j++) {
            if (party[i][j] == 0) break;
            if (res[party[i][j]]) {
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
