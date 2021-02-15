#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;

int N;
ll arr[11][2];

ll foo(int idx, int cnt, ll s, ll b) {
	if(idx == N) {
		if(cnt == 0) return 9999999999;
		return llabs(s-b);
	} else {
		return min(foo(idx+1, cnt+1, s*arr[idx][0], b+arr[idx][1]), foo(idx+1, cnt, s, b));
	}
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1];
	cout << foo(0, 0, 1, 0);

    return 0;
}