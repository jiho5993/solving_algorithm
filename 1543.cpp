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
    
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool chk[2501] = {0,};
    int cnt=0;
    fr(i, 0, a.size()) {
        if(a[i] == b[0] && !chk[i]) {
            bool equal = true;
            fr(j, 0, b.size()) {
                if(a[i+j] != b[j]) {
                    equal = false;
                    break;
                }
            }
            if(equal) {
                fr(j, i, i+b.size())
                    chk[j] = true;
                cnt++;
            }
        }
    }
    pt(cnt);

    return 0;
}s