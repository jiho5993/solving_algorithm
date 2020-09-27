#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[26];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<s.size(); j++) 
            arr[s[j]-'A'] += (int)pow(10, s.size()-j-1);
    }
    int res = 0;
    vector<int> v;
    for(auto i:arr) {
        if(i > 0) v.pb(i);
    }
    sort(all(v), greater<int>());
    for(int i=0, a=9; i<v.size(); i++, a--) res += v[i]*a;
    cout << res;

    return 0;
}