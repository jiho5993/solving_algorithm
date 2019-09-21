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
int n, m;
string arr[101];
bool visit[101][101];
typedef pair<int, pair<int, int> > piii;
priority_queue<piii, vector<piii>, greater<piii> > pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> m >> n;
    fr(i, 0, n) cin >> arr[i];
    visit[0][0] = 1;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        int w = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(x == m-1 && y == n-1) {
            pt(w);
            return 0;
        }
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n)) {
                if(!visit[yy][xx]) {
                    if(arr[yy][xx] == '0')
                        pq.push({w, {yy, xx}});
                    else pq.push({w+1, {yy, xx}});
                    visit[yy][xx] = 1;
                }
            }
        }
    }
}