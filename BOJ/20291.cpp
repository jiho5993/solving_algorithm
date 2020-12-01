#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    while(N--) {
        string s, ext=""; cin >> s;
        for(int i=s.size()-1; i>=0 && s[i] != '.'; i--)
            ext += s[i];
        reverse(all(ext));
        m[ext]++;
    }
    for(auto i:m) cout << i.first << ' ' << i.second << '\n';

    return 0;
}