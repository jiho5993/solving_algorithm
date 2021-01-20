#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
int arr[500001];
int tree[500001];
map<int, int> m;

void update(int i) {
    while(i <= N) {
        tree[i]++;
        i += (i & -i);
    }
}

int sum(int i) {
    int ret=0;
    while(i > 0) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=1; i<=N; i++) {
        int a; cin >> a;
        m[a] = i;
    }
    ll res=0;
    for(int i=0; i<N; i++) {
        int idx = m[arr[i]];
        res += (ll)sum(N)-(ll)sum(idx);
        update(idx);
    }
    cout << res;

    return 0;
}