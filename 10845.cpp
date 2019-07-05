#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int head, tail;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int size() {
    return tail-head;
}

bool empty() {
    return head == tail;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "push") {
            int val; cin >> val;
            push(val);
        } else if(s == "pop") {
            if(empty()) cout << -1 << '\n';
            else {
                cout << front() << '\n';
                pop();
            }
        } else if(s == "size") {
            cout << size() << '\n';
        } else if(s == "empty") {
            cout << empty() << '\n';
        } else if(s =="front") {
            if(empty()) cout << -1 << '\n';
            else cout << front() << '\n';
        } else {
            if(empty()) cout << -1 << '\n';
            else cout << back() << '\n';
        }
    }

    return 0;
}