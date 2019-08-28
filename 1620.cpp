#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

map<string, int> MAP;
string arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        arr[i] = s;
        MAP[s] = i;
    }
    while(m--) {
        string s; cin >> s;
        if(isdigit(s[0])) {
            pt(arr[stoi(s)-1]);
        } else {
            pt(MAP[s]+1);
        }
    }

    return 0;
}