#include <bits/stdc++.h>
using namespace std;

int S, T;

void foo() {
    map<long long, bool> m;
    queue<pair<string, long long> > qp;
    qp.push({"", S});
    while(!qp.empty()) {
        string s = qp.front().first;
        long long cur = qp.front().second;
        qp.pop();
        if(cur == T) {
            cout << s;
            return;
        }
        long long tmp = cur*cur;
        if(tmp <= T && !m[tmp]) {
            qp.push({s+"*", tmp});
            m[tmp] = 1;
        }
        tmp = cur+cur;
        if(tmp <= T && !m[tmp]) {
            qp.push({s+"+", tmp});
            m[tmp] = 1;
        }
        tmp = 1;
        if(tmp <= T && !m[tmp]) {
            qp.push({s+"/", tmp});
            m[tmp] = 1;
        }
    }
    cout << "-1";
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> S >> T;
    if(S == T) cout << 0;
    else foo();

    return 0;
}