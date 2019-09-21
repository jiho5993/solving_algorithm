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

const int INF = 1e9;
const int MOD = 1000000007;

bool p[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, cnt=0; cin >> n;
    p[1] = true;
    fr(i, 2, 1001) {
        if(p[i]) continue;
        for(int j=i*i; j<=1000; j+=i) p[j] = true;
    }
    while(n--) {
        int a; cin >> a;
        if(!p[a]) cnt++;
    }
    pt(cnt);

    return 0;
}