#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int a, b, c;
int dp[51][51][51];

int foo(int x, int y, int z) {
	if(x <= 0 || y <= 0 || z <= 0) return 1;
	if(x > 20 || y > 20 || z > 20) return foo(20, 20, 20);

	int &ret = dp[x][y][z];
	if(ret != -1) return ret;

	if(x < y && y < z)
		return ret = foo(x, y, z-1) + foo(x, y-1, z-1) - foo(x, y-1, z);
	else
		return ret = foo(x-1, y, z) + foo(x-1, y-1, z) + foo(x-1, y, z-1) - foo(x-1, y-1, z-1);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	while(1) {
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		memset(dp, -1, sizeof(dp));
		cout << "w(" << a << ", " << b << ", " << c << ") = " << foo(a, b, c) << '\n';
	}

    return 0;
}