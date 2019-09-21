#include <bits/stdc++.h>
using namespace std;

int n, mp[26][26], visit[26][26], num, cnt, apart[1001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y) {
    queue<pair<int, int> > qp;
    qp.push(make_pair(x, y));
    visit[x][y] = 1;

    while(!qp.empty()) {
        int x = qp.front().first;
        int y = qp.front().second;
        qp.pop();
        cnt++;

        for(int i=0; i<4; i++) {
            int xx = x + go[i][1];
            int yy = y + go[i][0];
            if((0 <= xx && xx < n) && (0 <= yy && yy < n) && mp[xx][yy] == 1 && visit[xx][yy] == 0)
                bfs(xx, yy);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++)
            mp[i][j] = s[j]-'0';
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cnt=0;
            if(mp[i][j] == 1 && visit[i][j] == 0) {
                bfs(i, j);
                apart[num++] = cnt;
            }
        }
    }
    printf("%d\n", num);
    sort(apart, apart+num);
    for(int i=0; i<num; i++) printf("%d\n", apart[i]);

    return 0;
}