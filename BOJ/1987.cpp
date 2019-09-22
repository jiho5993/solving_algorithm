#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int r, c, ans;
char arr[21][21];
bool isused[26];

void dfs(int rs, int y, int x) {
    ans = max(rs, ans);
    fr(i, 0, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        int idx = arr[yy][xx]-'A';
        if(xx < 0 || xx >= c || yy < 0 || yy >= r) continue;
        if(isused[idx]) continue;
        isused[idx] = true;
        dfs(rs+1, yy, xx);
        isused[idx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    fr(i, 0, r) {
        string s; cin >> s;
        fr(j, 0, c)
            arr[i][j] = s[j];
    }
    isused[arr[0][0]-'A'] = true;
    dfs(1, 0, 0);
    cout << ans << '\n';

    return 0;
}