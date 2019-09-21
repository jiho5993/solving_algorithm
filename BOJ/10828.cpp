#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int pos;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int size() {
    return pos;
}

bool empty() {
    return pos == 0;
}

int top() {
    return dat[pos-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "push") {
            int a; cin >> a;
            push(a);
        } else if(s == "pop") {
            if(empty()) cout << -1 << "\n";
            else  {
                cout << top() << "\n";
                pop();
            }
        } else if(s == "size") {
            cout << size() << '\n';
        } else if(s == "empty") {
            cout << empty() << '\n';
        } else {
            if(pos == 0) cout << -1 << '\n';
            else cout << top() << '\n';
        }
    }

    return 0;
}