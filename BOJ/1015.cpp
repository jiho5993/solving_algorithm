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
    
    int n; cin >> n;
    vector<pii> arr(n);
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr[i] = {a, i};
    }
    sort(all(arr));
    for(int i=0; i<n; i++) arr[i] = {arr[i].second, i};
    sort(all(arr));
    for(int i=0; i<n; i++) pt1(arr[i].second);

    return 0;
}