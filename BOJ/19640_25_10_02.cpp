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

struct info {
    int d, h, m;
    bool deca;
};

struct cmp {
    bool operator()(info a, info b) {
        if (a.d < b.d) return true;
        else if (a.d > b.d) return false;
        else {
            if (a.h < b.h) return true;
            else if (a.h > b.h) return false;
            else {
                if (a.m > b.m) return true;
                else return false;
            }
        }
    }
};

int N, M, K;
queue<pair<bool, pii> > q[100001];
priority_queue<info, vector<info>, cmp> pq;

void solve() {
    cin >> N >> M >> K;
    for (int i=0, m=0; i<N; i++, m++) {
        int a, b; cin >> a >> b;
        m %= M;
        if (i == K) q[m].push({true, {a, b}});
        else q[m].push({false, {a, b}});
    }

    for (int i=0; i<N && i<M; i++) {
        bool deca = q[i].front().first;
        int d = q[i].front().second.first;
        int h = q[i].front().second.second;
        q[i].pop();
        pq.push({d, h, i, deca});
    }

    int res = 0;
    while (1) {
        info i = pq.top();
        pq.pop();
        
        if (i.deca) break;
        res++;
        
        int idx = i.m;
        if (q[idx].empty()) continue;

        bool deca = q[idx].front().first;
        int d = q[idx].front().second.first;
        int h = q[idx].front().second.second;
        q[idx].pop();

        pq.push({d, h, idx, deca});
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
