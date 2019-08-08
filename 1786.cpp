#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

vector<int> f, occur;

vector<int> failure(string s) {
    vector<int> fv(s.size());
    int j=0;
    fr(i, 1, s.size()) {
        while(j > 0 && s[i] != s[j]) j = fv[j-1];
        if(s[i] == s[j]) fv[i] = ++j;
    }
    return fv;
}

vector<int> kmp(string a, string b) {
    vector<int> v;
    int j=0;
    fr(i, 0, a.size()) {
        while(j > 0 && a[i] != b[j]) j = f[j-1];
        if(a[i] == b[j]) j++;
        if(j == b.size()) {
            v.pb(i+2-b.size());
            j = f[j-1];
        }
    }

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    f = failure(b);
    occur = kmp(a, b);

    pt(occur.size());
    for(auto i : occur) pt1(i);

    return 0;
}