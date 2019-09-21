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

vector<int> fail;

vector<int> failure(string s) {
    vector<int> f(s.size());
    int j=0;
    fr(i, 1, s.size()) {
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

bool kmp(string a, string b) {
    int j=0;
    fr(i, 0, a.size()) {
        while(j > 0 && a[i] != b[j]) j = fail[j-1];
        if(a[i] == b[j]) j++;
        if(j == b.size()) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string a, b; cin >> a >> b;
    fail = failure(b);
    pt(kmp(a, b));

    return 0;
}