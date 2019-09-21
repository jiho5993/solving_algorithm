#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, s, arr[100001], rs=100005, sum=0, st=0, en=0;
    cin >> n >> s;
    fr(i, 0, n) cin >> arr[i];
    while(1) {
        if(sum >= s) {
            rs = min(rs, en-st);
            sum -= arr[st++];
        }
        else if(en == n) break;
        else sum += arr[en++];
    }
    rs == 100005 ? cout << '0' : cout << rs;

    return 0;
}