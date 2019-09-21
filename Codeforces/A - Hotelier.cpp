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

const int INF = 1e9;
const int MOD = 1000000007;

bool room[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    string s; cin >> s;
    fr(i, 0, n) {
        if(s[i] == 'L') {
            fr(j, 0, 10) 
                if(!room[j]) {
                    room[j] = 1;
                    break;
                }
        } else if(s[i] == 'R') {
            for(int j=9; j>=0; j--)
                if(!room[j]) {
                    room[j] = 1;
                    break;
                }
        } else room[s[i]-'0'] = 0;
    }
    fr(i, 0, 10) cout << room[i];

    return 0;
}