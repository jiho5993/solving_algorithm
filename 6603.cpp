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

int k;
int num[13];
int lot[50];
bool isused[50];

void dfs(int idx, int ss) {
    if(ss == 6) {
        fr(i, 0, 6) pt1(lot[i]);
        cout << '\n';
        return;
    }
    fr(i, idx, k) {
        if(!isused[i]) {
            isused[i] = 1;
            lot[ss] = num[i];
            dfs(i, ss+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while(1) {
        fill(isused, isused+50, 0);
        cin >> k;
        if(!k) break;
        fr(i, 0, k) cin >> num[i];
        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}