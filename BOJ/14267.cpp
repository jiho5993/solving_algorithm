#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, M;
vector<int> arr[100001];
int res[100001];

void dfs(int i) {
    for(auto t:arr[i]) {
        res[t] += res[i];
        dfs(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        int a; cin >> a;
        if(i != 1) arr[a].pb(i);
    }
    while(M--) {
        int a, b; cin >> a >> b;
        res[a] += b;
    }
    dfs(1);
    for(int i=1; i<=N; i++) cout << res[i] << ' ';

    return 0;
}