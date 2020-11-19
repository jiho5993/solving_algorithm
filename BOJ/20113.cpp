#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[101];
vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        arr[a]++;
    }
    int mx = *max_element(arr+1, arr+N+1);
    for(int i=1; i<=N; i++)
        if(arr[i] == mx)
            v.pb(mp(mx, i));
    if(v.size() > 1) cout << "skipped";
    else cout << v[0].second;

    return 0;
}