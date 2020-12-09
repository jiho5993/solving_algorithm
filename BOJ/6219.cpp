#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int A, B, D, res=0;
bool p[4000001];

void eratos() {
    p[1] = true;
    for(int i=2; i*i<=B; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=B; j+=i) p[j] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> A >> B >> D;
    eratos();
    for(int i=A; i<=B; i++) {
        if(p[i]) continue;
        int tmp = i;
        while(tmp%10 != D && tmp) tmp /= 10;
        if(!tmp) continue;
        else res++;
    }
    cout << res;

    return 0;
}