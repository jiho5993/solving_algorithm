#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAX = 2'000'005;
int N;
int tree[MAX];

void update(int i, int v) {
    for(; i<=MAX; i+=(i&-i)) tree[i]+=v;
}

int query(int i) {
    int ret=0;
    for(; i>0; i-=(i&-i)) ret += tree[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    while(N--) {
        int a, b; cin >> a >> b;
        if(a == 1) update(b, 1);
        else {
            int l=1, r=MAX-5;
            while(l < r) {
                int mid = (l+r)>>1;
                if(query(mid) >= b) r = mid;
                else l = mid+1;
            }
            cout << l << '\n';
            update(l, -1);
        }
    }

    return 0;
}