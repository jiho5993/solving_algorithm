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

#define MAX 10000001

bool arr[MAX];
vector<ll> prime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    for(int i=2; i*i<MAX; i++) {
        if(arr[i]) continue;
        for(int j=i*2; j<MAX; j+=i) arr[j] = true;
    }
    fr(i, 2, MAX)
        if(!arr[i])
            prime.pb(i);
    ll a, b, rs=0; cin >> a >> b;
    fr(i, 0, prime.size()) {
        ll tmp = prime[i];
        while(b/tmp >= prime[i]) {
            if(prime[i]*tmp >= a) rs++;
            tmp *= prime[i];
        }
    }
    pt(rs);

    return 0;
}