#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int a, b, c;
int t[101], m = 0, rs = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    fr(i, 0, 3) {
        int q, w; cin >> q >> w;
        fr(j, q, w) t[j]++;
        m = max(m, w);
    }
    fr(i, 1, m+1) {
        if(t[i] == 1) rs += a;
        if(t[i] == 2) rs += (b*2);
        if(t[i] == 3) rs += (c*3);
    }
    cout << rs;

    return 0;
}