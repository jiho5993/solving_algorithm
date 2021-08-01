#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        m[s]++;
    }
    vector<pair<string, int> > arr(all(m));
    sort(all(arr), [](auto a, auto b) {
        string aa = a.first, bb = b.first;
        if(a.second == b.second) {
            if(aa.size() == bb.size()) return aa < bb;
            else return aa.size() > bb.size();
        }
        return a.second > b.second;
    });
    for(auto [i,j]:arr) {
        if(i.size() >= M) cout << i << '\n';
    }

    return 0;
}