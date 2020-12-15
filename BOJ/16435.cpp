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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, L; cin >> N >> L;
    int arr[1001];
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    for(int i=0; i<N; i++) {
        if(arr[i] <= L) L++;
        else break;
    }
    cout << L;

    return 0;
}