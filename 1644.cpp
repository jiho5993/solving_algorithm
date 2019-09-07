#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define MAX 4000001

int n, rs;
vector<int> prime;
vector<bool> chk;

void eratos() {
    chk.resize(n+1, true);
    for(int i=2; i*i<=n; i++) {
        if(!chk[i]) continue;
        for(int j=i*i; j<=n; j+=i) chk[j] = false;
    }
    fr(i, 2, n+1)
        if(chk[i])
            prime.pb(i);
}

void tp() {
    int st=0, en=0, sum=0;
    while(1) {
        if(sum >= n) sum -= prime[st++];
        else if(en == prime.size()) break;
        else sum += prime[en++];
        if(sum == n) rs++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    eratos();
    tp();
    cout << rs;

    return 0;
}