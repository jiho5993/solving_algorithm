#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
#define pt3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pt4(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int a, b, c, arr[10]={0,}; cin >> a >> b >> c;
    string s = to_string(a*b*c);
    fr(i, 0, len(s)) arr[s[i]-'0']++;
    fr(i, 0 , 10) pt(arr[i]);

    return 0;
}