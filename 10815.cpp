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

int arr[500001];

int bs(int st, int en, int val) {
    if(st > en) return 0;
    int mid = (st+en)/2;
    if(arr[mid] == val) return 1;
    else if(arr[mid] < val) bs(mid+1, en, val);
    else bs(st, mid-1, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n1, n2; cin >> n1;
    fr(i, 0, n1) cin >> arr[i];
    sort(arr, arr+n1);
    cin >> n2;
    while(n2--) {
        int val; cin >> val;
        pt1(bs(0, n1, val));
    }

    return 0;
}