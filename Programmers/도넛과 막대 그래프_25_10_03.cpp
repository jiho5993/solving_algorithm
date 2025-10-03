#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

#define MAX 1000000

vector<int> adj[MAX+1];
int cnt1[MAX+1], cnt2[MAX+1];
unordered_set<int> e;
int st;
map<pii, bool> visited;

int bfs(int st, int x) {
    int ed = 0;
    queue<int> q;
    unordered_set<int> v;
    
    q.push(x);
    v.insert(st);
    visited[{st, x}] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        ed++;
        v.insert(x);

        for (int n: adj[x]) {
            if (visited[{x, n}]) continue;
            visited[{x, n}] = true;
            q.push(n);
        }
    }
    
    if (v.size() == ed) return 1;
    else if (v.size()-1 == ed) return 2;
    else return 3;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    for (auto i: edges) {
        adj[i[0]].push_back(i[1]);
        cnt1[i[0]]++;
        cnt2[i[1]]++;
        e.insert(i[0]);
        e.insert(i[1]);
    }

    for (auto i: e) {
        if (cnt1[i] > 1) {
            if (cnt2[i] == 0) {
                st = i;
                break;
            }
        }
    }

    answer[0] = st;

    for (int x: adj[st]) {
        int res = bfs(st, x);
        answer[res]++;
    }

    return answer;
}
