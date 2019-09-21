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

bool paper[101][101];
int rs=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
	while(n--) {
		int a, b; cin >> a >> b;
		for(int i=a; i<a+10; i++) {
			for(int j=b; j<b+10; j++) {
				if(!paper[i][j]) rs++;
				paper[i][j] = 1;
			}
		}
	}
	pt(rs);

    return 0;
}