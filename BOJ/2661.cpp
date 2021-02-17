#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;

void foo(int sz, string res) {
    for(int i=1; i<=sz/2; i++) {
        if(res.substr(sz-i, i) == res.substr(sz-i*2, i)) {
            res = "";
            return;
        }
    }
    if(sz > N) return;
    if(sz == N) {
        cout << res;
        exit(0);
    } else {
        for(int i=1; i<=3; i++)
            foo(sz+1, res+to_string(i));
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    foo(0, "");

    return 0;
}