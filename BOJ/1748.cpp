#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int N; cin >> N;
    long long res=0;
    string s = to_string(N);
    if(s.size() == 1) {
        cout << N;
        return 0;
    }
    for(int i=0; i<s.size()-1; i++) res += 9*(i+1)*(long long)pow(10, i);
    for(int i=(int)pow(10, s.size()-1); i<=N; i++) res += s.size();
    cout << res;

    return 0;
}