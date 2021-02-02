#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

double cnt=0;
map<string, double> m;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	string s;
	while(getline(cin, s)) {
		m[s]++;
		cnt++;
	}
	cout << fixed;
	cout.precision(4);
	for(auto i:m) cout << i.first << ' ' << (i.second/cnt)*100 << '\n';

    return 0;
}