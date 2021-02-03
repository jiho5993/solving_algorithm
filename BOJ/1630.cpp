#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
const ll MOD = 987654321;
int N;
bool p[1000001];

void eratos() {
	p[1] = 1;
	for(int i=2; i*i<=N; i++) {
		if(p[i]) continue;
		for(int j=i<<1; j<=N; j+=i) p[j] = 1;
	}
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	cin >> N;
	eratos();
	ll res=1;
	for(int i=2; i<=N; i++) {
		if(p[i]) continue;
		ll tmp = i;
		while(tmp*i <= N) tmp *= i;
		res = (res*tmp)%MOD;
	}
	cout << res;

    return 0;
}