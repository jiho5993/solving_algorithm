#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

class Tree {
    public:
    int v;
    Tree *lc, *rc;

    Tree(int val) {
        v = val;
        lc = NULL;
        rc = NULL;
    }
};

Tree *tree;
int arr[10001];

void make(Tree *cur, Tree *prev, int v, bool flag) {
    if (cur == NULL) {
        if (flag) prev->lc = new Tree(v);
        else prev->rc = new Tree(v);
        return;
    }

    if (cur->v > v) make(cur->lc, cur, v, true);
    else if (cur->v < v) make(cur->rc, cur, v, false);
}

void post_order(Tree *cur) {
    if (cur->lc != NULL) post_order(cur->lc);
    if (cur->rc != NULL) post_order(cur->rc);
    cout << cur->v << '\n';
}

void solve() {
    int a, N=0;
    while (cin >> a) arr[N++] = a;

    tree = new Tree(arr[0]);

    for (int i=1; i<N; i++) make(tree, NULL, arr[i], false);

    post_order(tree);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
