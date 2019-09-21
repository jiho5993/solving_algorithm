#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

int l, C;
int ja_cnt=0, mo_cnt=0;
char c[15];
char pw[15];
bool isused[26];

void dfs(int idx, int ss) {
    if(ss == l) {
        if(ja_cnt >= 2 && mo_cnt >= 1) {
            fr(i, 0, l) cout << pw[i];
            cout << '\n';
        }
        return;
    }
    fr(i, idx, C) {
        if(!isused[i]) {
            if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u') mo_cnt++;
            else ja_cnt++;
            isused[i] = 1;
            pw[ss] = c[i];
            dfs(i, ss+1);
            isused[i] = 0;
            if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u') mo_cnt--;
            else ja_cnt--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> l >> C;
    fr(i, 0, C) cin >> c[i];
    sort(c, c+C);
    dfs(0, 0);

    return 0;
}