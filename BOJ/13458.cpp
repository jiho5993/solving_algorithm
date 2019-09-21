#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n, arr[1000001], a, b;
long long rs=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) cin >> arr[i];
    cin >> a >> b;
    fr(i, 0, n) {
        arr[i] -= a;
        rs++;
        if(arr[i] > 0) {
            if(arr[i]%b == 0) rs += (arr[i]/b);
            else rs += (arr[i]/b)+1;
        }
    }
    cout << rs;

    return 0;
}