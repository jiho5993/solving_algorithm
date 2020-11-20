#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

map<int, string> m;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s;
        int a;
        cin >> s >> a;
        m.insert(mp(a, s));
    }
    while(M--) {
        int a; cin >> a;
        auto idx = m.lower_bound(a);
        cout << idx->second << '\n';
    }

    return 0;
}