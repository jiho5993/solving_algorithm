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

int lcs[1005][1005];
string s1, s2, s3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> s1 >> s2;
    s1 = '0'+s1;
    s2 = '0'+s2;
    int ss1 = s1.size(), ss2 = s2.size();
    fr(i, 1, ss2) {
        fr(j, 1, ss1) {
            if(s2[i] == s1[j]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    pt(lcs[ss2-1][ss1-1]);
    ss1--, ss2--;
    while(ss2 > 0 && ss1 > 0) {
        if(lcs[ss2][ss1] == lcs[ss2][ss1-1]) ss1--;
        else if(lcs[ss2][ss1] == lcs[ss2-1][ss1]) ss2--;
        else if(lcs[ss2][ss1]-1 == lcs[ss2-1][ss1-1]) {
            s3 += s1[ss1];
            ss1--, ss2--;
        }
    }
    reverse(all(s3));
    pt(s3);

    return 0;
}