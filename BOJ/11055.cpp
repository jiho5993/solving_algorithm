#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[1001], dp[1001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> arr[i];

	for(int i=1; i<=N; i++) {
		dp[i] = arr[i];
		for(int j=1; j<=i; j++) {
			if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	cout << *max_element(dp+1, dp+N+1);

    return 0;
}