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

int arr[10001];
int n, m;

int bs(int st, int en) {
    int s=0, rs=0;
    while(st < en) {
        int mid = (st+en)/2;
        int ss = 0;
        fr(i, 0, n) {
            if(arr[i] > mid) ss += mid;
            else ss += arr[i];
        }
        if(ss <= m) {
            if(s < ss) {
                s = ss;
                rs = mid;
            }
            st = mid+1;
        } else en = mid;
    }
    return rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) cin >> arr[i];
    cin >> m;
    int mm = *max_element(arr, arr+n);
    pt(min(mm, bs(0, m)));

    return 0;
}