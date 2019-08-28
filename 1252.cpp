#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int compare_len(string &a, string &b) {
    int len;
    bool fa=0, fb=0;
    if(a.size() > b.size()) {
        len = a.size()-b.size();
        fb = 1;
    } else {
        len = b.size()-a.size();
        fa = 1;
    }
    if(fa)
        for(int i=0; i<len; i++)
            a = '0'+a;
    else
        for(int i=0; i<len; i++)
            b = '0'+b;
    a = '0'+a;
    b = '0'+b;
    return a.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string a, b, rs=""; cin >> a >> b;
    int len = compare_len(a, b);
    bool flag = false;
    for(int i=len-1; i>=0; i--) {
        if(flag) {
            if(a[i] == '1' && b[i] == '1') rs += '1';
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) rs += '0';
            else {
                rs += '1';
                flag = false;
            }
        } else {
            if(a[i] == '1' && b[i] == '1') {
                flag = true;
                rs += '0';
            } else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) rs += '1';
            else rs += '0';
        }
    }
    reverse(all(rs));
    while(rs[0] == '0') rs.erase(0, 1);
    rs.empty() ? pt(0) : pt(rs);

    return 0;
}