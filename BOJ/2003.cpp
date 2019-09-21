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

int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, m; cin >> n >> m;
    fr(i, 0, n) cin >> arr[i];
    ll st=0, en=0, sum=0, cnt=0;
    while(1) {
        if(sum >= m) sum -= arr[st++];
        else if(en == n) break;
        else sum += arr[en++];
        if(sum == m) cnt++;
    }
    pt(cnt);

    return 0;
}