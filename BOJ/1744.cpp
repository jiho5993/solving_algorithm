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

vector<int> pos_arr;
vector<int> neg_arr;
ll n, val, rs=0, prev=0;
ll pos_idx=0, neg_idx=0;
ll one, zero;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        cin >> val;
        if(val > 1) pos_arr.pb(val);
        else if(val < 0) neg_arr.pb(val);
        else if(val == 1) one++;
        else zero++;
    }
    sort(all(pos_arr), greater<int>());
    sort(all(neg_arr));
    for(int i=0; i<pos_arr.size(); i+=2) {
        if(i+1 == pos_arr.size()) {
            rs += pos_arr[i];
            break;
        }
        rs += pos_arr[i] * pos_arr[i+1];
    }
    for(int i=0; i<neg_arr.size(); i+=2) {
        if(i+1 == neg_arr.size() && !zero) {
            rs += neg_arr[i];
            break;
        }
        rs += neg_arr[i] * neg_arr[i+1];
    }
    pt(rs+one);

    return 0;
}