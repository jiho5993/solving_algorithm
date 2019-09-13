#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b; cin >> a >> b;
    string s = to_string(a);
    s[s.size()-1] = s[s.size()-2] = '0';
    a = stoi(s);
    fr(i, a, a+100)
        if(i%b == 0) {
            s = to_string(i);
            cout << s[s.size()-2] << s[s.size()-1];
            break;
        }

    return 0;
}