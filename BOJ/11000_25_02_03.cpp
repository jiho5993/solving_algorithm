#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

pii arr[200001];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr+N);

    int res = 1;
    pq.push(arr[0].second);
    
    for (int i=1; i<N; i++) {
        if (arr[i].first < pq.top()) {
            res++;
        } else {
            pq.pop();
        }
        pq.push(arr[i].second);
    }

    cout << res;

    return 0;
}
