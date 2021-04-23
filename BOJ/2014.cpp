#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;

int K, N;
int arr[101];
priority_queue<ll, vector<ll>, greater<ll> > pq;
ll res = 0;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	cin >> K >> N;
	for(int i=0; i<K; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	while(N--) {
		ll tmp = pq.top();
		res = tmp;
		pq.pop();
		for(int i=0; i<K; i++) {
			ll ret = tmp * arr[i];
			pq.push(ret);
			if(tmp%arr[i] == 0) break;
		}
	}
	cout << res;

    return 0;
}