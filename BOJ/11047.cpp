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

int arr[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int cnt=0;
    int n, k; cin >> n >> k;
    fr(i, 0, n) cin >> arr[i];
    for(int i=n-1; i>=0 && k > 0; i--) {
        int val = k/arr[i];
        k -= val*arr[i];
        cnt += val;
    }
    pt(cnt);

    return 0;
}