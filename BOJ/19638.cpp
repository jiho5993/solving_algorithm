#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int cnt=0, prv;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, H, T; cin >> N >> H >> T;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        pq.push(a);
    }
    for(int i=0; i<T; i++) {
        int tmp = pq.top();
        if(tmp < H) {
            cout << "YES\n" << i;
            return 0;
        } else if(tmp > 1) {
            pq.pop();
            pq.push(tmp/2);
        }
    }
    if(pq.top() < H) cout << "YES\n" << T;
    else cout << "NO\n" << pq.top();

    return 0;
}