#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

int n, w, l;
int val;
int cnt=0, weight=0;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> w >> l;
    while(n--) {
        cin >> val;
        while(1) {
            if(sz(q) == w) {
                weight -= q.front();
                q.pop();
            }
            if(q.empty()) {
                q.push(val);
                cnt++;
                weight += val;
                break;
            } else {
                if(weight+val > l) {
                    q.push(0);
                    cnt++;
                } else {
                    q.push(val);
                    cnt++;
                    weight += val;
                    break;
                }
            }
        }
    }
    pt(cnt+w);

    return 0;
}