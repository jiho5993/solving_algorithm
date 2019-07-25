#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

int dp_0[45]={1, 0};
int dp_1[45]={0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t, n; cin >> t;
    fr(i, 2, 41) {
        dp_0[i] = dp_0[i-2] + dp_0[i-1];
        dp_1[i] = dp_1[i-2] + dp_1[i-1];
    }
    while(t--) {
        cin >> n;
        pt2(dp_0[n], dp_1[n]);
        cout << '\n';
    }

    return 0;
}