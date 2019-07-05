#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int dat[MAX];
int head = MAX/2, tail = MAX/2;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int size() {
    return tail-head;
}

bool empty() {
    return tail == head;
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
        if(s == "push_front") {
            int x; cin >> x;
            push_front(x);
        } else if(s == "push_back") {
            int x; cin >> x;
            push_back(x);
        } else if(s == "pop_front") {
            if(empty()) cout << "-1" << '\n';
            else {
                cout << front() << '\n';
                pop_front();
            }
        } else if(s == "pop_back") {
            if(empty()) cout << "-1" << '\n';
            else {
                cout << back() << '\n';
                pop_back();
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