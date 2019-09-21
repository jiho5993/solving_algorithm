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

ll cnt;
int arr[500005];
int rs[500005];

void merge(int st, int mid, int en) {
    int i = st;
    int j = mid+1;
    int k = st;
    while(i <= mid && j <= en) {
        if(arr[i] <= arr[j])
            rs[k++] = arr[i++];
        else {
            rs[k++] = arr[j++];
            cnt += mid+1-i;
        }
    }
    int tmp = i > mid ? j : i;
    while(k <= en) rs[k++] = arr[tmp++];
    fr(i, st, en+1) arr[i] = rs[i];
}

void divide(int st, int en) {
    if(st < en) {
        int mid = (st+en)/2;
        divide(st, mid);
        divide(mid+1, en);
        merge(st, mid, en);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    fr(i, 0, n) cin >> arr[i];
    divide(0, n-1);
    pt(cnt);

    return 0;
}