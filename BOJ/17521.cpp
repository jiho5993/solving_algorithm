#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ll long long
#define V(T) vector<T>
#define VP(T) vector<pair<T, T> >
#define P(T) pair<T, T>
#define PQ(T) priority_queue<T>

ll arr[16];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    ll N, W, coin=0; cin >> N >> W;
    for(int i=0; i<N; i++) cin >> arr[i];
    bool flag = false;
    for(int i=0; i<N; i++) {
        if(arr[i] < arr[i+1] && !flag) {
            coin += W / arr[i];
            W %= arr[i];
            flag = true;
        } else if(arr[i] > arr[i+1] && flag) {
            W += (arr[i] * coin);
            coin = 0;
            flag = false;
        }
    }
    cout << W + arr[N-1]*coin;

    return 0;
}