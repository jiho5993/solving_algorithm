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

int low_bs(int val, int st, int en) {
    while(st < en) {
        int mid = (st+en)/2;
        if(arr[mid] >= val) en = mid;
        else st = mid+1;
    }
    return st;
}

int up_bs(int val, int st, int en) {
    while(st < en) {
        int mid = (st +en)/2;
        if(arr[mid] > val) en = mid;
        else st = mid+1;
    }
    return st;
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
        pt1(up_bs(val, 0, n1) - low_bs(val, 0, n1));
    }

    return 0;
}