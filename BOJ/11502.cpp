#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

bool p[1001];
vector<int> arr;

void eratos() {
    p[1] = 1;
    for(int i=2; i*i<=1000; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=1000; j+=i) p[j] = 1;
    }
    for(int i=2; i<=1000; i++)
        if(!p[i]) arr.pb(i);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    eratos();

    int T; cin >> T;
    while(T--) {
        int a; cin >> a;
        bool flag = false;
        for(int i:arr) {
            for(int j:arr) {
                for(int k:arr) {
                    if(i + j + k == a) {
                        cout << i << ' ' << j << ' ' << k << '\n';
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout << 0 << '\n';
    }

    return 0;
}