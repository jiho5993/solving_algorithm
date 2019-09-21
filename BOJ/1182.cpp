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

int n, s;
int cnt;
int arr[21];

void dfs() {
    fr(i, 1, 1 << n) {
        int tmp = i;
        int rs=0;
        fr(j, 0, n) {
            if(tmp%2 == 1) rs += arr[j];
            tmp /= 2;
        }
        if(rs == s) cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> s;
    fr(i, 0, n) cin >> arr[i];
    dfs();
    pt(cnt);

    return 0;
}