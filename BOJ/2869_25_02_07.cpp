#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int A, B, V; cin >> A >> B >> V;

    int res = (V-B-1)/(A-B) + 1;
    cout << res;

    return 0;
}
