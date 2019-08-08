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

ll arr[100001];
ll rs = 100000001*2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n; cin >> n;
    fr(i, 0, n) cin >> arr[i];
    ll st=0, en=n-1;
    while(st < en) {
        ll tmp = arr[st] + arr[en];
        if(abs(tmp) < abs(rs)) rs = tmp;
        if(tmp < 0) st++;
        else en--;
    }
    pt(rs);

    return 0;
}