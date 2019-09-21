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
    
    string n; cin >> n;
    int arr[10]={0,}, big=0;
    fr(i, 0, len(n)) arr[n[i]-'0']++;
    arr[6] = (arr[6]+arr[9])/2 + ((arr[6]+arr[9])%2 == 1);
    fr(i, 0, 9) {
        if(big < arr[i])
            big = arr[i];
    }
    pt(big);

    return 0;
}