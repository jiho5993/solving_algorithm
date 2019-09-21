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

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int a, b, sum=0; cin >> a >> b;
    for(int i=1; i<=b; i++) {
        int num = i;
        while(num--) v.pb(i);
    }
    for(int i=a; i<=b; i++) sum += v[i-1];
    pt(sum);

    return 0;
}