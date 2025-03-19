#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N, M;
char s[55][55], n_s[55][55];

int pop1(char target) {
    bool visited[55][55] = {0,};
    queue<pair<int, int> > qp;
    qp.push({0, 0});
    visited[0][0] = true;
    memcpy(n_s, s, sizeof(char)*55*55);
    
    int res = 0;
    while (!qp.empty()) {
        int x = qp.front().first, y = qp.front().second;
        qp.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if (s[nx][ny] == target && !visited[nx][ny]) {
                n_s[nx][ny] = 0;
                visited[nx][ny] = true;
                res++;
                continue;
            }
            if (s[nx][ny] != 0 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            qp.push({nx, ny});
        }
    }
    memcpy(s, n_s, sizeof(char)*55*55);
    return res;
}

int pop2(char target) {
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (s[i][j] == target) {
                s[i][j] = 0;
                res++;
            }
        }
    }
    return res;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    memset(s, 0, sizeof(char)*55*55);
    
    N = storage.size() + 1;
    M = storage[0].size() + 1;
    for (int i=1; i<=N-1; i++) {
        for (int j=1; j<=M-1; j++) {
            s[i][j] = storage[i-1][j-1];
        }
    }
    answer = (N-1)*(M-1);

    int del = 0;
    for (auto i: requests) {
        if (i.size() == 1) {
            del += pop1(i[0]);
        } else {
            del += pop2(i[0]);
        }
    }

    return answer - del;
}
