#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int query, n; cin >> query;
    while(query--) {
        int arr[401]; cin >> n;
        for(int i=0; i<n*4; i++) cin >> arr[i];
        sort(arr, arr+4*n);
        int s = arr[0]*arr[4*n-1];
        bool flag = false;
        for(int i=0; i<4*n; i+=2)
            if(arr[i]*arr[4*n-i-1] != s || arr[i]!=arr[i+1])
                flag=true;
        flag ? pt("NO") : pt("YES");
    }

    return 0;
}