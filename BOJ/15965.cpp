#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

bool p[10000001];
vector<int> prime;

void eratos() {
    p[1] = true;
    for(int i=2; i*i<=10000001; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=10000001; j+=i) p[j] = true;
    }
    for(int i=2; i<=10000001; i++) {
        if(!p[i])
            prime.pb(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    int N; cin >> N;
    eratos();
    cout << prime[N-1];

    return 0;
}