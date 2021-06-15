#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, K, res=1000001;
vector<int> lion;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        if(a == 1) lion.pb(i);
    }
    if(K > lion.size()) {
        cout << -1;
        return 0;
    }
    for(int i=0; i<lion.size()-K+1; i++)
        res = min(res, lion[i+K-1] - lion[i] + 1);
    cout << res;

    return 0;
}