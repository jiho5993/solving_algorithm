#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> arr(n);
        fr(i, 0, n) cin >> arr[i];
        sort(all(arr));
        bool flag = false;
        fr(i, 1, n) {
            if(arr[i-1] == arr[i].substr(0, arr[i-1].size())) {
                flag = true;
                break;
            }
        }
        flag ? cout << "NO\n" : cout << "YES\n";
    }

    return 0;
}