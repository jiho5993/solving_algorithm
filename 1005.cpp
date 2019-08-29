#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k, w, what_time[1001]={0}, degree[1001]={0}, rs[1001]={0};
        vector<vector<int> > mat(1001);
        cin >> n >> k;
        fr(i, 1, n+1) cin >> what_time[i];
        fr(i, 0, k) {
            int a, b; cin >> a >> b;
            degree[b]++;
            mat[a].pb(b);
        }
        cin >> w;
        queue<int> q;
        fr(i, 1, n+1)
            if(!degree[i])
                q.push(i);
        
        while(degree[w]>0) {
            int tmp = q.front();
            q.pop();
            for(auto i : mat[tmp]) {
                rs[i] = max(rs[i], rs[tmp]+what_time[tmp]);
                if(!(--degree[i]))
                    q.push(i);
            }
        }
        pt(rs[w]+what_time[w]);
    }

    return 0;
}