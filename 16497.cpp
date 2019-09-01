#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vii;
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

int arr[32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin >> n;
    fr(i, 0, n) {
        int a, b; cin >> a >> b;
        fr(j, a, b) arr[j]++;
    }
    cin >> k;
    bool flag = true;
    fr(i, 1, 32) {
        if(arr[i] > k) {
            flag = false;
            break;
        }
    }
    pt(flag);

    return 0;
}