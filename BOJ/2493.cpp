#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, arr[500001]={0,}, x; cin >> n;
    stack<pair<int, int> > sp;
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(sp.empty()) sp.push(make_pair(i, x));
        else {
            while(sp.top().second < x) {
                sp.pop();
                if(sp.empty()) break;
            }
            if(!sp.empty()) arr[i] = sp.top().first;
            sp.push(make_pair(i, x));
        }
    }
    for(int i=1; i<=n; i++) cout << arr[i] << ' ';

    return 0;
}