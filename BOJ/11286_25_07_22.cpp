#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int heap[200005];
int ptr = 0;

bool cmp(int a, int b) {
    if (abs(a) < abs(b)) return false;
    else if (abs(a) == abs(b)) {
        if (a < b) return false;
        else return true;
    }
    return true;
}

void insert(int x) {
    if (ptr == 0) {
        heap[++ptr] = x;
        return;
    }

    heap[++ptr] = x;
    int tmp = ptr;

    while (1) {
        if (tmp == 1) break;

        if (cmp(heap[tmp/2], heap[tmp])) {
            swap(heap[tmp/2], heap[tmp]);
            tmp /= 2;
            continue;
        }
        break;
    }
}

int del() {
    if (ptr == 0) {
        return 0;
    }

    int res = heap[1];
    swap(heap[1], heap[ptr--]);

    int tmp = 1;

    while (1) {
        int l = tmp*2, r = tmp*2 + 1;
        int target;

        if (l > ptr) break;
        if (r > ptr) target = l;
        else {
            if (abs(heap[l]) < abs(heap[r])) target = l;
            else if (abs(heap[l]) > abs(heap[r])) target = r;
            else {
                if (heap[l] < heap[r]) target = l;
                else target = r;
            }
        }

        if (cmp(heap[tmp], heap[target])) {
            swap(heap[tmp], heap[target]);
            tmp = target;
            continue;
        }
        break;
    }

    return res;
}

void solve() {
    int N; cin >> N;
    while (N--) {
        int a; cin >> a;
        if (a == 0) {
            cout << del() << '\n';
        }
        else {
            insert(a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
