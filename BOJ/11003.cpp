#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

int N, L;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        pq.push({a, i});
        while(pq.top().second <= i-L) pq.pop();
        cout << pq.top().first << ' ';
    }

    return 0;
}