#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s;
    int N, res=0;
    cin >> s >> N;
    for(int i=0; i<N; i++) {
        string tmp; cin >> tmp;
        tmp += tmp;
        if(tmp.find(s) != string::npos) res++;
    }
    cout << res;

    return 0;
}