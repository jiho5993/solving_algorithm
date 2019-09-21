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

ll init(vl &arr, vl &tree, int node, int st, int en) {
    if(st == en) return tree[node] = arr[st];
    int mid = (st+en)/2;
    return tree[node] = init(arr, tree, node*2, st, mid) + init(arr, tree, node*2+1, mid+1, en);
}

void update(vl &tree, int node, int st, int en, int target_node, ll val) {
    if(!(st <= target_node && target_node <= en)) return;
    tree[node] += val;
    if(st != en) {
        int mid = (st+en)/2;
        update(tree, node*2, st, mid, target_node, val);
        update(tree, node*2+1, mid+1, en, target_node, val);
    }
}

ll sum(vl &tree, int node, int st, int en, int left, int right) {
    if(st > right || en < left) return 0;
    if(left <= st && en <= right) return tree[node];
    int mid = (st+en)/2;
    return sum(tree, node*2, st, mid, left, right) + sum(tree, node*2+1, mid+1, en, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vl tree(n*4), arr(n+1, 0);
    init(arr, tree, 1, 0, n-1);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) { // sum
            if(b > c) swap(b, c);
            pt(sum(tree, 1, 0, n-1, b-1, c-1));
        } else { // update
            ll val = c - arr[b-1];
            arr[b-1] = c;
            update(tree, 1, 0, n-1, b-1, val);
        }
    }

    return 0;
}