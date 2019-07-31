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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int rs=0;
    string s, tmp=""; cin >> s;
    bool chk=false;
    fr(i, 0, s.size()+1) {
        if(s[i] == '-' || s[i] == '+' || s[i] == '\0') {
            if(chk) rs -= stoi(tmp);
            else rs += stoi(tmp);
            tmp.clear();
            if(s[i] == '-') chk = true;
        }
        else tmp += s[i];
    }
    pt(rs);

    return 0;
}