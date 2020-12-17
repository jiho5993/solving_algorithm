#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long
#define V(T) vector<T>
#define VP(T) vector<pair<T,T>>
#define P(T) pair<T,T>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>

P(int) arr[200001];
GPQ(int) pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, res=0; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+N);
    pq.push(arr[0].second);
    for(int i=1; i<N; i++) {
        if(pq.top() <= arr[i].first) {
            pq.pop();
            pq.push(arr[i].second);
        } else pq.push(arr[i].second);
    }
    cout << pq.size();

    return 0;
}