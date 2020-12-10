#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

	int res=0;
	for(int i=0; i<8; i++) {
		string s; cin >> s;
		for(int j=0; j<8; j++) {
			if(s[j] == 'F') {
				if(i%2 == 0 && j%2 == 0) res++;
				else if(i%2 == 1 && j%2 == 1) res++;
			}
		}
	}
	cout << res;

    return 0;
}