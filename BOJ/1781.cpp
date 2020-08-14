#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

pair<int, int> arr[200001];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr+N);
    long long ret = 0;
    int dl = 0;
    for(int i=0; i<N; i++) {
        dl = arr[i].X;
        pq.push(-arr[i].Y);
        while(dl < pq.size()) pq.pop();
    }
    while(!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }
    cout << -ret;

    return 0;
}