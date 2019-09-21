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
const int MOD = 15746;

int a[100001];

int bs(int val, int start, int end) {
    int mid = (start+end)/2;
    if(start > end) return 0;
    if(a[mid] < val) bs(val, mid+1, end);
    else if(a[mid] > val) bs(val, start, mid-1);
    else return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n1, n2; cin >> n1;
    fr(i, 0, n1) cin >> a[i];
    sort(a, a+n1);
    cin >> n2;
    fr(i, 0, n2) {
        int val; cin >> val;
        int idx = bs(val, 0, n1-1);
        pt(idx);
    }

    return 0;
}