#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[1001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        arr[a]++;
    }
    cout << *max_element(arr+1, arr+N+1);

    return 0;
}