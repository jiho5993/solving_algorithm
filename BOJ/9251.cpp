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

const int INF = 2147483648;
const int MOD = 1000000007;

int lcs[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s1, s2; cin >> s1 >> s2;
    s1 = '0'+s1;
    s2 = '0'+s2;
    fr(i, 1, s1.size()) {
        fr(j, 1, s2.size()) {
            if(s1[i] == s2[j]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }
    pt(lcs[s1.size()-1][s2.size()-1]);

    return 0;
}