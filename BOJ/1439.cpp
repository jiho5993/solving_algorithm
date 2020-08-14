#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s, ss=""; cin >> s;
    s.erase(unique(all(s)), s.end());
    int _0=0, _1=0;
    for(auto i:s) i-'0' ? _1++ : _0++;
    cout << min(_1, _0);

    return 0;
}