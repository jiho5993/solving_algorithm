#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int a, b; cin >> a >> b;
    if(a > 0) {
        if(b > 0) cout << 1;
        else cout << 4;
    } else {
        if(b > 0) cout << 2;
        else cout << 3;
    }

    return 0;
}