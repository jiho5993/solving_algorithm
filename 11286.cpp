#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int n; cin >> n;
    while(n--) {
        int cmd; cin >> cmd;
        if(!cmd) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        } else pq.push({abs(cmd), cmd});
    }

    return 0;
}