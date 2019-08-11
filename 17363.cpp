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

char draw[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    fr(i, 0, n) {
        string s; cin >> s;
        fr(j, 0, m)
            draw[i][j] = s[j];
    }
    for(int i=m-1; i>=0; i--) {
        fr(j, 0, n) {
            char p = draw[j][i];
            if(p == '.') cout << '.';
            else if(p == 'O') cout << 'O';
            else if(p == '-') cout << '|';
            else if(p == '|') cout << '-';
            else if(p == '/') cout << '\\';
            else if(p == '\\') cout << '/';
            else if(p == '^') cout << '<';
            else if(p == '<') cout << 'v';
            else if(p == 'v') cout << '>';
            else cout << '^';
        }
        cout << '\n';
    }

    return 0;
}