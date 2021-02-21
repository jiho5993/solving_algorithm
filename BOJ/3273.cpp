#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[100001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

	int N, X, res=0; cin >> N;
	for(int i=0; i<N; i++) cin >> arr[i];
	sort(arr, arr+N);
	cin >> X;
	int i=0, j=N-1;
	while(i < j) {
		int tmp = arr[i]+arr[j];
		if(tmp < X) i++;
		else if(tmp > X) j--;
		else {
			res++;
			i++;
		}
	}
	cout << res;

    return 0;
}