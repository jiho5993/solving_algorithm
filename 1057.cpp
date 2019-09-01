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

bool arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, k, cnt=1; cin >> n >> m >> k;
    arr[m] = arr[k] = 1;
    while(n) {
        int idx = 1;
        if(n%2 == 0) {
            for(int i=2; i<=n; i+=2) {
                bool f=arr[i-1], s=arr[i];
                if(f && s) {
                    pt(cnt);
                    return 0;
                }
                if(f || s) arr[idx++] = 1;
                else if(!f && !s) arr[idx++] = 0;
            }
            n /= 2;
        } else {
            for(int i=2; i<=n; i+=2) {
                bool f=arr[i-1], s=arr[i];
                if(f && s) {
                    pt(cnt);
                    return 0;
                }
                if(f || s) arr[idx++] = 1;
                else if(!f && !s) arr[idx++] = 0;
            }
            if(arr[n]) arr[idx++] = 1;
            else arr[idx++] = 0;
            n /= 2;
            n++;
        }
        cnt++;
    }
    pt(-1);
}