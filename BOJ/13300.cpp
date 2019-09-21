#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k, arr[6][2]={0,}, s, y, cnt=0; cin >> n >> k;
    fr(i, 0, n) {
        cin >> s >> y;
        arr[y-1][s]++;
    }
    fr(i, 0, 6) {
        fr(j, 0, 2) {
            if(!arr[i][j]) continue;
            cnt += arr[i][j]/k;
            if(arr[i][j] - (arr[i][j]/k)*k > 0) cnt++;
        }
    }
    pt(cnt);

    return 0;
}