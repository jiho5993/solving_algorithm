#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[10] = {100, 100, 200, 200, 300, 300, 400, 400, 500};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int s=0;
    for(int i=0; i<9; i++) {
        int a; cin >> a;
        if(a > arr[i]) {
            cout << "hacker";
            return 0;
        }
        s += a;
    }
    if(s >= 100) cout << "draw";
    else cout << "none";

    return 0;
}