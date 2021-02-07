#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int res=0;
bool arr[101];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        arr[a] ? res++ : arr[a] = 1;
    }
    cout << res;

    return 0;
}