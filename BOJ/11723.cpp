#include <bits/stdc++.h>
using namespace std;

int N;
map<int, bool> m;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    while(N--) {
        string query; cin >> query;
        if(query == "add") {
            int val; cin >> val;
            m[val] = true;
        } else if(query == "remove") {
            int val; cin >> val;
            m[val] = false;
        } else if(query == "check") {
            int val; cin >> val;
            if(m[val]) cout << "1\n";
            else cout << "0\n";
        } else if (query == "toggle") {
            int val; cin >> val;
            m[val] = !m[val];
        } else if (query == "all") {
            for(int i=1; i<=20; i++)
                m[i] = true;
        } else if (query == "empty") {
            m.clear();
        }
    }

    return 0;
}