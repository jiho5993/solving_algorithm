#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
double cnt, W;
int arr[500001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> W;
    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        arr[a]++;
        arr[b]++;
    }
    for(int i=2; i<=N; i++) cnt += (arr[i] == 1);
    cout.precision(11);
    cout << W/cnt;

    return 0;
}