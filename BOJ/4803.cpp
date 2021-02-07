#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, M;
vector<int> arr[501];
bool visit[501];

bool foo(int v, int pv) {
    visit[v] = 1;
    for(auto i:arr[v]) {
        if(i == pv) continue;
        if(visit[i]) return false;
        if(!foo(i, v)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int T=1;
    while(cin >> N >> M) {
        if(N == 0) break;
        int res=0;
        for(int i=0; i<501; i++) arr[i].clear();
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            arr[a].pb(b);
            arr[b].pb(a);
        }
        for(int i=1; i<=N; i++)
            if(!visit[i])
                res += foo(i, 0);
        cout << "Case " << T++ << ": ";
        if(res > 1) cout << "A forest of " << res << " trees.\n";
        else if(res == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
    }

    return 0;
}