#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, a, b; cin >> r >> c >> a >> b;
    fr(i, 0, r) {
        fr(j, 0, a) {
            fr(k, 0, c) {
                if((i+k)%2 == 0)
                    fr(l, 0, b)
                        cout << 'X';
                else
                    fr(l, 0, b)
                        cout << '.';
            }
            cout << '\n';
        }
    }

    return 0;
}