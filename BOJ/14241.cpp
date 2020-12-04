#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N;
int res=0;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        pq.push(a);
    }
    while(pq.size() != 1) {
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        pq.pop();
        res += (t1*t2);
        pq.push(t1+t2);
    }
    cout << res;

    return 0;
}