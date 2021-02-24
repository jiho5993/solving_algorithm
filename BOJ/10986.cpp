#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll N, M, s=0, res=0;
ll arr[1000005];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	cin >> N >> M;
	for(int i=0; i<N; i++) {
		ll a; cin >> a;
		s = (s+a)%M;
		if(!s) res++;
		arr[s]++;
	}
	for(int i=0; i<N; i++)
		if(arr[i] > 0)
			res += (arr[i]*(arr[i]-1))/2;
	cout << res;

    return 0;
}