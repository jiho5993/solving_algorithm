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

int n;
int arr[65][65];

void quadTree(int ss, int x, int y) {
    if(ss == 1) {
        cout << arr[x][y];
        return;
    }
    bool chk = false;
    fr(i, x, x+ss) {
        if(chk) break;
        fr(j, y, y+ss) {
            if(arr[x][y] != arr[i][j]) {
                chk = true;
                break;
            }
        }
    }

    if(!chk) cout << arr[x][y];
    else {
        cout << "(";
        int nss = ss/2;
        quadTree(nss, x, y);
        quadTree(nss, x, y + nss);
        quadTree(nss, x + nss, y);
        quadTree(nss, x + nss, y + nss);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        string s; cin >> s;
        fr(j, 0, n)
            arr[i][j] = s[j]-'0';
    }
    quadTree(n, 0, 0);

    return 0;
}