#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; getline(cin, s);
    fr(i, 0, s.size()) {
        if('a' <= s[i] && s[i] <= 'm') s[i] += 13;
        else if('n' <= s[i] && s[i] <= 'z') s[i] -= 13;
        else if('A' <= s[i] && s[i] <= 'M') s[i] += 13;
        else if('N' <= s[i] && s[i] <= 'Z') s[i] -= 13;
    }
    cout << s;

    return 0;
}