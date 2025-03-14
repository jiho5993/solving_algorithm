#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M, L;
bool m[51];
int p[51];
vector<int> arr[51];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (m[x]) p[y] = x;
    else p[x] = y;
}

void solve() {
    cin >> N >> M >> L;
    for (int i=1; i<=N; i++) p[i] = i;
    for (int i=0; i<L; i++) {
        int a; cin >> a;
        m[a] = true;
    }

    for (int i=0; i<M; i++) {
        int K; cin >> K;
        for (int j=0; j<K; j++) {
            int a; cin >> a;
            arr[i].push_back(a);
        }

        if (arr[i].size() >= 2) {
            for (int j=1; j<K; j++) {
                merge(arr[i][j-1], arr[i][j]);
            }
        }
    }

    int res = 0;
    for (int i=0; i<M; i++) {
        if (!m[find(arr[i][0])]) res++;
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
