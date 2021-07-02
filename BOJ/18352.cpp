#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int INF = 987654321;
int N, M, K, X;
vector<int> arr[300001];
int dist[300001];

bool foo(int st) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, st));
    dist[st] = 0;
    while(!pq.empty()) {
        int d = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(auto i:arr[v]) {
            if(dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                pq.push(make_pair(-dist[i], i));
            }
        }
    }
    bool flag = false;
    for(int i=1; i<=N; i++) {
        if(dist[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> M >> K >> X;
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a].pb(b);
    }
    fill(dist, dist+N+1, INF);
    if(!foo(X)) cout << -1;

    return 0;
}