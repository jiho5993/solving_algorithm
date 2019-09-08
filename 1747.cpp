#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define MAX 2000001

bool arr[MAX];
vector<int> prime;

bool ispalin(string s) {
    int sz = s.size();
    fr(i, 0, sz/2)
        if(s[i] != s[sz-1-i])
            return false;
    return true;
}

void eratos() {
    arr[1] = true;
    for(int i=2; i*i<MAX; i++) {
        if(arr[i]) continue;
        for(int j=i*i; j<MAX; j+=i) arr[j] = true;
    }
    fr(i, 2, MAX)
        if(!arr[i] && ispalin(to_string(i)))
            prime.pb(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    eratos();
    for(auto i:prime) {
        if(i >= n) {
            cout << i;
            break;
        }
    }

    return 0;
}