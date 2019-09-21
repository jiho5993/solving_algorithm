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

pair<ll, ll> findOfZero(ll num) {
    ll two=0, five=0;
    for(ll i=1; i<=num; i*=2)
        two += num/i;
    for(ll i=1; i<=num; i*=5)
        five += num/i;
    return {two, five};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, m; cin >> n >> m;
    pair<ll, ll> a = findOfZero(n);
    pair<ll, ll> b = findOfZero(n-m);
    pair<ll, ll> c = findOfZero(m);
    pt(min(a.first-b.first-c.first, a.second-b.second-c.second));

    return 0;
}