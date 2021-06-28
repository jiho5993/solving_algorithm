#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll dist[5001];
vector<pair<ll, ll> > arr[5001];

void dfs(int cur, int prev) {
	for(auto i : arr[cur]) {
		if(dist[i.first] > dist[cur] + i.second && prev != i.first) {
			dist[i.first] = dist[cur] + i.second;
			dfs(i.first, cur);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	cin >> N;
	for(int i=2; i<=N; i++) {
		ll a, b, c; cin >> a >> b >> c;
		arr[a].push_back({b, c});
		arr[b].push_back({a, c});
		dist[i] = 5e13;
	}
	
	dfs(1, 0);
	cout << *max_element(dist+2, dist+N+1);
	
	return 0;
}
