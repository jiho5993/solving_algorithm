#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, cnt=0; cin >> N;
    string s; cin >> s;
    for(int i=0; i<N; i++) {
        if(s[i] == 'J' || s[i] == 'A' || s[i] == 'V') {
            cnt++;
            continue;
        }
        cout << s[i];
    }
    if(cnt == N) cout << "nojava";

    return 0;
}