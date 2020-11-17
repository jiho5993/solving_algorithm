#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

vector<pair<int, string> > v;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        int a;
        cin >> s >> a;
        v.pb(mp(-a, s));
    }
    sort(all(v));
    cout << v[0].second << '\n';

    return 0;
}