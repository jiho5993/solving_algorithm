#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
#define pt3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pt4(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, arr[101], a, cnt=0; cin >> n;
    fr(i, 0, n) cin >> arr[i];
    cin >> a;
    fr(i, 0, n) cnt += (arr[i] == a);
    pt1(cnt);

    return 0;
}