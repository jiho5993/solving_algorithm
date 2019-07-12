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

void star(int x, int y) {
    while(x != 0 || y != 0) {
        if(x%3 == 1 && y%3 == 1) {
            cout << " ";
            return;
        }
        x /= 3;
        y /= 3;
    }
    cout << "*";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    fr(i, 0, n) {
        fr(j, 0, n)
            star(i, j);
        pt("");
    }

    return 0;
}