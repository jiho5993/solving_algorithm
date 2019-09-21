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

ll init(vector<ll> &arr, vector<ll> &tree, int node, int st, int en) {
    if(st == en)
        return tree[node] = arr[st];
    int mid = (st+en)/2;
    return tree[node] = ((init(arr, tree, node*2, st, mid)%MOD) * (init(arr, tree, node*2 + 1, mid+1, en)%MOD))%MOD;
}

ll update(vector<ll> &tree, int node, int st, int en, int target_node, ll val) {
    if(!(st <= target_node && target_node <= en))
        return tree[node];
    
    if(st == en) return tree[node] = val;
    int mid = (st+en)/2;
    return tree[node] = ((update(tree, node*2, st, mid, target_node, val)%MOD) * (update(tree, node*2 + 1, mid+1, en, target_node, val)%MOD))%MOD;
}

ll mult(vector<ll> &tree, int node, int st, int en, int left, int right) {
    if(left > en || right < st)
        return 1;
    if(left <= st && en <= right)
        return tree[node]%MOD;
    
    int mid = (st+en)/2;
    return ((mult(tree, node*2, st, mid, left, right)%MOD) * (mult(tree, node*2 + 1, mid+1, en, left, right)%MOD))%MOD;
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, k; cin >> n >> m >> k;
    int tree_size = n*4;

    vector<ll> arr(n); 
    vector<ll> tree(tree_size);
 
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    init(arr, tree, 1, 0, n-1);
 
    m += k;

    while (m--) {
        cin.ignore();
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            update(tree, 1, 0, n-1, b-1, c);
        } else pt(mult(tree, 1, 0, n-1, b-1, c-1)%MOD);
    }

    return 0;
}