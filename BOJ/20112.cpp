#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

string arr[101];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++) {
        string s="";
        for(int j=0; j<N; j++) s += arr[j][i];
        if(s != arr[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}