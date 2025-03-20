#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

vector<int> arr[100001];
vector<int> dist(100001, -1);

void bfs(int st) {
    queue<pair<int, int> > qp;
    qp.push({st, 0});
    dist[st] = 0;

    while (!qp.empty()) {
        int x = qp.front().first, d = qp.front().second;
        qp.pop();

        for (auto n: arr[x]) {
            if (dist[n] == -1) {
                dist[n] = d + 1;
                qp.push({n, d+1});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size());

    for (auto i: roads) {
        arr[i[0]].push_back(i[1]);
        arr[i[1]].push_back(i[0]);
    }

    bfs(destination);

    for (int i=0; i<sources.size(); i++) {
        answer[i] = dist[sources[i]];
    }

    return answer;
}
