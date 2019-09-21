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

int N, R, C;
int cnt;
void Z(int a, int b, int c) {
    if(a == 2) {
        if(b == R && c == C) {
            pt(cnt++);
            return;
        }
        cnt++;
        if(b == R && c+1 == C) {
            pt(cnt++);
            return;
        }
        cnt++;
        if(b+1 == R && c == C) {
            pt(cnt++);
            return;
        }
        cnt++;
        if(b+1 == R && c+1 == C) {
            pt(cnt++);
            return;
        }
        cnt++;
        return;
    }

    Z(a/2, b, c); // 1
    Z(a/2, b, c+a/2); // 2
    Z(a/2, b+a/2, c); // 3
    Z(a/2, b+a/2, c+a/2); // 4
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> R >> C;
    Z(pow(2, N), 0, 0);

    return 0;
}