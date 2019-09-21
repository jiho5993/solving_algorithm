#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, val, cnt=0; cin >> n >> m;
    deque<int> dq;
    for(int i=1; i<=n; i++) dq.push_back(i);
    while(m--) {
        cin >> val;
        int sz = dq.size(), idx=0;
        for(auto itr = dq.begin(); itr != dq.end(); itr++) {
            if(*itr == val) break;
            idx++;
        }
        int a = sz-idx;
        if(a > idx) {
            for(int i=0; i<idx; i++) {
                dq.push_back(*dq.begin());
                dq.pop_front();
                cnt++;
            } dq.pop_front();
        } else {
            for(int i=0; i<a; i++) {
                dq.push_front(*(dq.end()-1));
                dq.pop_back();
                cnt++;
            } dq.pop_front();
        }
    }
    cout << cnt;

    return 0;
}