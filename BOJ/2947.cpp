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

	int arr[5];
	for(int i=0; i<5; i++) cin >> arr[i];
	while(1) {
		bool flag = true;
		for(int i=0; i<5; i++) {
			if(arr[i] != i+1) 
				flag = false;
		}
		if(flag) break;
		for(int i=0; i<4; i++) {
			if(arr[i] > arr[i+1]) {
				swap(arr[i], arr[i+1]);
				for(int j=0; j<5; j++) cout << arr[j] << ' ';
				cout << '\n';
			}
		}
	}

    return 0;
}