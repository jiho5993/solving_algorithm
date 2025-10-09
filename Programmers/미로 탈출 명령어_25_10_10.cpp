#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char d[] = {'d', 'l', 'r', 'u'};
int N, M;
int R, C;
int K;
bool flag = false;
string res = "";

void dfs(int x, int y, string s) {
    if (res < s) return;
    if (abs(x-R)+abs(y-C) > K-s.size()) return;
    if (s.size() > K) return;
    if (s.size() == K && x == R && y == C) {
        if (res > s) {
            flag = true;
            res = s;
        }
        return;
    }

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 >= nx || nx > N || 0 >= ny || ny > M) continue;
        string tmp = s;
        tmp += d[i];
        dfs(nx, ny, tmp);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if ((abs(x-r)+abs(y-c))%2 != k%2) return "impossible";
    
    for (int i=0; i<2500; i++) res += 'z';
    N = n, M = m;
    R = r, C = c;
    K = k;

    dfs(x, y, "");

    return flag ? res : "impossible";
}
