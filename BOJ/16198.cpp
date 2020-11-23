#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, arr[11];
bool chk[11];

int foo() {
    int res=0;
    for(int i=1; i<N-1; i++) {
        if(chk[i]) continue;
        chk[i] = true;
        int l=i-1, r=i+1;
        while(chk[l]) l--;
        while(chk[r]) r++;
        res = max(res, foo()+arr[l]*arr[r]);
        chk[i] = false;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    cout << foo();

    return 0;
}