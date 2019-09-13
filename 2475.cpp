#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << (a*a + b*b + c*c + d*d + e*e)%10;

    return 0;
}