#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

map<int, bool> m;
int a1[101], a2[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int a; cin >> a;
    for(int i=0; i<a; i++) {
        cin >> a1[i];
        m[a1[i]] = true;
    }
    int b; cin >> b;
    for(int i=0; i<b; i++) {
        cin >> a2[i];
        m[a2[i]] = true;
    }
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            if(!m[a1[i]+a2[j]]) {
                cout << a1[i] << " " << a2[j] << '\n';
                return 0;
            }
        }
    }
}