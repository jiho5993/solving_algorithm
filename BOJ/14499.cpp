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

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int n, m, x, y, k, go;
int MAP[20][20];
int dice[7];

void foo(int next) {
    int temp[7];
    fr(i, 1, 7) temp[i] = dice[i];
    if(next == 1) {
        dice[1] = temp[4];
        dice[3] = temp[1];
        dice[4] = temp[6];
        dice[6] = temp[3];
    } else if(next == 2) {
        dice[1] = temp[3];
        dice[3] = temp[6];
        dice[4] = temp[1];
        dice[6] = temp[4];
    } else if(next == 3) {
        dice[1] = temp[5];
        dice[2] = temp[1];
        dice[5] = temp[6];
        dice[6] = temp[2];
    } else {
        dice[1] = temp[2];
        dice[2] = temp[6];
        dice[5] = temp[1];
        dice[6] = temp[5];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m >> x >> y >> k;
    fr(i, 0, n) {
        fr(j, 0, m)
            cin >> MAP[i][j];
    }
    while(k--) {
        cin >> go;
        int xx = x + dx[go-1];
        int yy = y + dy[go-1];
        if((0 <= xx && xx < n) && (0 <= yy && yy < m)) {
            foo(go);
            if(MAP[xx][yy] == 0)
                MAP[xx][yy] = dice[6];
            else {
                dice[6] = MAP[xx][yy];
                MAP[xx][yy] = 0;
            }
            x = xx;
            y = yy;
            pt(dice[1]);
        }
    }

    return 0;
}