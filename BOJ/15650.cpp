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

int n, m;
int arr[8];
bool isused[8];

void dfs(int idx, int ss) {
    if(ss == m) {
        fr(i, 0, m) pt1(arr[i]+1);
        cout << '\n';
        return;
    }
    fr(i, idx, n) {
        if(!isused[i]) {
            arr[ss] = i;
            isused[i] = 1;
            dfs(i, ss+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    dfs(0, 0);

    return 0;
}