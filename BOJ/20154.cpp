#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int arr[26]={3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s; cin >> s;
    int res = 0;
    for(auto i:s) res = (res+arr[i-'A'])%10;
    cout << (res&1 ? "I'm a winner!" : "You're the winner?");

    return 0;
}