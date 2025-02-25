#include <bits/stdc++.h>
using namespace std;

int minheap[200002];
int sz = 0;

int pop() {
    if (sz == 0) return 0;

    int res = minheap[1];
    minheap[1] = minheap[sz--];

    int x = 1;
    while (1) {
        int idx = -1;
        if (minheap[2*x] < minheap[2*x+1]) idx = 2*x;
        else idx = 2*x+1;

        if (idx > sz || minheap[x] < minheap[idx]) {
            break;
        }

        swap(minheap[x], minheap[idx]);
        x = idx;
    }

    return res;
}

void insert(int v) {
    int x = ++sz;
    minheap[x] = v;

    while (1) {
        if (x == 1 || minheap[x] > minheap[x/2]) break;

        swap(minheap[x], minheap[x/2]);
        x = x/2;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int Q; cin >> Q;
    while (Q--) {
        int a; cin >> a;
        if (a == 0) {
            cout << pop() << '\n';
        } else {
            insert(a);
        }
    }

    return 0;
}
