#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<N*N; i++) {
        int a; cin >> a;
        pq.push(a);
        if(pq.size() > N) pq.pop();
    }
    cout << pq.top();

    return 0;
}