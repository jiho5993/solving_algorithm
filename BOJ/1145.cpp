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
    
    int arr[5], s=1;
    fr(i, 0, 5) cin >> arr[i];
    while(1) {
        int cnt=0;
        fr(i, 0, 5)
            if(s%arr[i] == 0)
                cnt++;
        if(cnt > 2) {
            pt(s);
            break;
        }
        s++;
    }

    return 0;
}