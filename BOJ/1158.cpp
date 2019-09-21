#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k, cnt=1;; cin >> n >> k;
    queue<int> q;
    fr(i, 1, n+1) q.push(i);
    cout << "<";
    while(sz(q) != 1) {
        if(cnt == k) {
            cout << q.front() << ", ";
            cnt = 1;
            q.pop();
        } else {
            cnt++;
            q.push(q.front());
            q.pop();
        }
    }
    cout << q.front() << ">";

    return 0;
}