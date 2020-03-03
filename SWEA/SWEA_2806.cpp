#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int rs = 0;
bool vis1[15], vis2[30], vis3[30];

void foo(int n, int ss) {
    if (n == ss) {
        rs++;
        return;
    }
    fr(i, 0, n) {
        if (!vis1[i] && !vis2[ss + i] && !vis3[ss - i + n - 1]) {
            vis1[i] = 1;
            vis2[ss + i] = 1;
            vis3[ss - i + n - 1] = 1;
            foo(n, ss + 1);
            vis1[i] = 0;
            vis2[ss + i] = 0;
            vis3[ss - i + n - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    fr(tc, 1, t + 1) {
        fill(vis1, vis1 + 15, false);
        fill(vis2, vis2 + 30, false);
        fill(vis3, vis3 + 30, false);
        int n;
        rs = 0;
        cin >> n;
        foo(n, 0);
        cout << "#" << tc << ' ' << rs << '\n';
    }

    return 0;
}