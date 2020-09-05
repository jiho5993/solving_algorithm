#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    ll N; cin >> N;
    if(N%5 == 2 || N%5 == 0) cout << "CY";
    else cout << "SK";

    return 0;
}