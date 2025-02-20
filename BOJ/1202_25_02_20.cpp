#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

pii arr[300001];
multiset<int> s;

bool cmp(pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    for (int i=0; i<K; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    sort(arr, arr+N, cmp);

    long long res = 0;
    for (int i=0; i<N; i++) {
        auto t = s.lower_bound(arr[i].first);
        if (t == s.end()) continue;
        s.erase(t);
        res += arr[i].second;
        if (s.empty()) break;
    }

    cout << res;

    return 0;
}
