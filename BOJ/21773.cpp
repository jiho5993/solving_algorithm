#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef tuple<int, int, int> tii;

struct cmp {
    bool operator() (tii a, tii b) {
        int aa[3], bb[3];
        tie(aa[0], aa[1], aa[2]) = a;
        tie(bb[0], bb[1], bb[2]) = b;
        if(aa[2] == bb[2]) return aa[0] > bb[0];
        return aa[2] < bb[2];
    }
};

int T, n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> T >> n;
    priority_queue<tii, vector<tii>, cmp> pq;
    for(int i=0; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    while(!pq.empty() && T--) {
        int a, b, c;
        tie(a, b, c) = pq.top();
        pq.pop();
        cout << a << '\n';
        if(b-1 == 0) continue;
        else pq.push({a, b-1, c-1});
    }

    return 0;
}