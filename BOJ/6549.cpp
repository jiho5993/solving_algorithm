#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(vector<ll> &arr, vector<int> &tree, int node, int st, int en) {
    if(st == en) tree[node] = st;
    else {
        int mid = (st+en)/2;
        init(arr, tree, node*2, st, mid);
        init(arr, tree, node*2+1, mid+1, en);
        if(arr[tree[node*2]] <= arr[tree[node*2+1]])
            tree[node] = tree[node*2];
        else
            tree[node] = tree[node*2+1];
    }
}

int query(vector<ll> &arr, vector<int> &tree, int node, int st, int en, int left, int right) {
    if(left > en || right < st) return -1;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    int idx1 = query(arr, tree, node*2, st, mid, left, right);
    int idx2 = query(arr, tree, node*2+1, mid+1, en, left, right);

    if(idx1 == -1) return idx2;
    else if(idx2 == -1) return idx1;
    else return arr[idx1] <= arr[idx2] ? idx1 : idx2;
}

ll getMax(vector<ll> &arr, vector<int> &tree, int st, int en) {
    int N = arr.size();
    int idx = query(arr, tree, 1, 0, N-1, st, en);
    ll sz = (ll)(en-st+1)*(ll)arr[idx];
    if(st <= idx-1) sz = max(sz, getMax(arr, tree, st, idx-1));
    if(idx+1 <= en) sz = max(sz, getMax(arr, tree, idx+1, en));
    return sz;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    while(1) {
        int N; cin >> N;
        if(!N) break;
        vector<ll> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i];

        vector<int> tree(N*4);
        init(arr, tree, 1, 0, N-1);
        cout << getMax(arr, tree, 0, N-1) << '\n';
    }

    return 0;
}