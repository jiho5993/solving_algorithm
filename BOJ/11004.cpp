#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, a; cin >> n >> k;
    vector<long> v;
    for(int i=0; i<n; i++) {
        cin >> a;
        v.push_back(a);
    } sort(v.begin(), v.end());
    printf("%ld\n", v[k-1]);

    return 0;
}