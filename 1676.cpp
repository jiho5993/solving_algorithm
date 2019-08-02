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
    
    int n, cnt=0; cin >> n;
    fr(i, 1, n+1) {
        int tmp = i;
        while(tmp%2 == 0 || tmp%5 == 0) { // 어차피 2 아니면 5가 나온것만 찾으면 됨
            if(tmp%2 == 0) tmp /= 2;
            if(tmp%5 == 0) {
                tmp /= 5;
                cnt++;
            }
        }
    }
    pt(cnt);

    return 0;
}