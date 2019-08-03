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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, cnt=0; cin >> n;
        bool arr[101];
        fr(i, 1, n+1) arr[i] = 1;
        fr(i, 2, n+1)
            for(int j=i; j<=n; j+=i)
                arr[j] = !arr[j];
        fr(i, 1, n+1)
            if(arr[i])
                cnt++;
        pt(cnt);
    }

    return 0;
}