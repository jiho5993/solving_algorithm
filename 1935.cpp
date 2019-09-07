#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, arr[26]; cin >> n;
    string s; cin >> s;
    stack<double> sd;
    fr(i, 0, n) cin >> arr[i];
    fr(i, 0, s.size()) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            double a, b;
            a = sd.top(), sd.pop(), b = sd.top(), sd.pop();
            switch (s[i])
            {
            case '+':
                sd.push(b+a);
                break;
            case '-':
                sd.push(b-a);
                break;
            case '*':
                sd.push(b*a);
                break;
            case '/':
                sd.push(b/a);
                break;
            }
        } else sd.push(arr[s[i]-'A']);
    }
    cout << fixed;
    cout.precision(2);
    cout << sd.top();

    return 0;
}