#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2e9;
const int MOD = 1000000007;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int arr[126][126], d[126][126];
int n, cnt = 1;
vector<vector<pii> > adj(20202);

int dij() {
    priority_queue<pii> pq;
    vi dist(20202, INF);
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        if(dist[tmp] < cost) continue;
        for(auto i : adj[tmp]) {
            int there = i.first;
            int new_cost = i.second + cost;
            if(dist[there] > new_cost) {
                dist[there] = new_cost;
                pq.push({-new_cost, there});
            }
        }
    }
    return dist[d[n][n]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int c=1;
    fr(i, 1, 126)
        fr(j, 1, 126)
            d[i][j] = c++;
    while(1) {
        cin >> n;
        if(!n) return 0;
        fr(i, 0, 20202) adj[i].clear();
        fr(i, 1, n+1) {
            fr(j, 1, n+1) 
                cin >> arr[i][j];
        }
        adj[0].pb({1, arr[1][1]});
        fr(i, 1, n+1) {
            fr(j, 1, n+1) {
                fr(k, 0, 4) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x < 1 || y < 1 || x > n || y > n) continue;
                    adj[d[i][j]].pb({d[x][y], arr[x][y]});
                }
            }
        }
        cout << "Problem " << cnt++ << ": " << dij() << '\n';
    }
}