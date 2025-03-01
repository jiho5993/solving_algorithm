#include <bits/stdc++.h>
using namespace std;

int N;
bool arr[51][51];
bool visited[51][51];
int score[51];
vector<int> res;

int bfs(int st) {
    queue<pair<int, int> > qp;
    qp.push({st, 0});
    int dist[51] = {0,};
    for (int i=1; i<=N; i++) dist[i] = 1e5;

    int ret = -1;

    while (!qp.empty()) {
        int x = qp.front().first, d = qp.front().second;
        qp.pop();
        visited[st][x] = true;
        dist[x] = min(dist[x], d);
        ret = max(ret, dist[x]);

        for (int i=1; i<=N; i++) {
            if (!arr[x][i] || visited[st][i]) continue;
            qp.push({i, d + 1});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    while (1) {
        int a, b; cin >> a >> b;
        if (a == -1 && b == -1) break;
        arr[a][b] = arr[b][a] = true;
    }

    int min_score = 1e5;
    for (int i=1; i<=N; i++) {
        score[i] = bfs(i);
        min_score = min(min_score, score[i]);
    }


    for (int i=1; i<=N; i++) {
        if (min_score == score[i]) {
            res.push_back(i);
        }
    }

    cout << min_score << ' ' << res.size() << '\n';
    for (auto i: res) cout << i << ' ';

    return 0;
}
