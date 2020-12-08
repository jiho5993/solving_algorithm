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

	int N, M;
	string s;
	cin >> N >> M >> s;
	int res=0;
	for(int i=0; i<M; i++) {
		if(s[i] == 'I' && s[i+1] == 'O') {
			int sz = 0;
			while(s[i+1] == 'O' && s[i+2] == 'I') {
				i += 2;
				sz++;
				if(s[i] == 'I' && sz == N) {
					res++;
					sz--;
				}
			}
		}
	}
	cout << res;

    return 0;
}