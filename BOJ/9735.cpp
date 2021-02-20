#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	int T; cin >> T;
	cout << fixed;
	cout.precision(4);
	while(T--) {
		ld a, b, c, d, x; cin >> a >> b >> c >> d;
		for(ld i=-1000000; i<=1000000; i++) {
			if(a*i*i*i + b*i*i + c*i + d == 0) {
				x = i;
				break;
			}
		}
		ld x1 = a;
		ld x2 = b + x1*x;
		ld x3 = c + x2*x;
		ld D = x2*x2-4*x1*x3;
		set<ld> s;
		if(D >= 0) {
			ld v=sqrt(D);
			s.insert(x);
			s.insert((-x2+v)/(2*x1));
			s.insert((-x2-v)/(2*x1));
			for(auto i=s.begin(); i!=s.end(); i++) cout << *i << ' ';
			cout << '\n';
		} else cout << x << '\n';
	}

    return 0;
}