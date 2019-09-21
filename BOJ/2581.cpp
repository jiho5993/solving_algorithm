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

bool p[10001], flag = false;

void eratos(int b) {
    for(int i=2; i*i<=b; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=b; j+=i) p[j] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int a, b, m=10001, rs=0; cin >> a >> b;
    p[1] = true;
    eratos(b);
    for(int i=a; i<=b; i++) {
        if(p[i]) continue;
        m = min(m, i);
        rs += i;
        flag = true;
    }
    if(flag) cout << rs << '\n' << m;
    else pt(-1);

    return 0;
}