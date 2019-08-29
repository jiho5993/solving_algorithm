#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

ll init(vl &arr, vl &tree, int node, int st, int en) {
    if(st == en) return tree[node] = arr[st];
    int mid = (st+en)/2;
    return tree[node] = min(init(arr, tree, node*2, st, mid), init(arr, tree, node*2+1, mid+1, en));
}

ll find_min(vl &tree, int node, int st, int en, int left, int right) {
    if(st > right || en < left) return INF;
    if(left <= st && en <= right) return tree[node];
    int mid = (st+en)/2;
    return min(find_min(tree, node*2, st, mid, left, right), find_min(tree, node*2+1, mid+1, en, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vl tree(n*4), arr(n);
    fr(i, 0, n) cin >> arr[i];
    init(arr, tree, 1, 0, n-1);
    while(m--) {
        int a, b; cin >> a >> b;
        pt(find_min(tree, 1, 0, n-1, a-1, b-1));
    }

    return 0;
}