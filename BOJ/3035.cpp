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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    char n[51][51];
    int a, b, c, d; cin >> a >> b >> c >> d;
    for(int i=0; i<a; i++) {
        string s; cin >> s;
        for(int j=0; j<c; j++) {
            for(int k=0; k<b; k++)
                for(int l=0; l<d; l++)
                    cout << s[k];
            cout << '\n';
        }
    }

    return 0;
}