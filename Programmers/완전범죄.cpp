#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define vvi vector<vector<int> >

int res = 1e9;
int mxN, mxM;
bool dp[41][121][121];

void dfs(vvi info, int idx, int n, int m) {
    if (n >= mxN || m >= mxM) return;
    
    if (idx == info.size()) {
        res = min(res, n);
        return;
    }

    if (dp[idx][n][m]) return;
    dp[idx][n][m] = true;
    
    dfs(info, idx+1, n+info[idx][0], m);
    dfs(info, idx+1, n, m+info[idx][1]);
}

int solution(vector<vector<int>> info, int n, int m) {
    mxN = n, mxM = m;
    dfs(info, 0, 0, 0);

    return res == 1e9 ? -1 : res;
}
