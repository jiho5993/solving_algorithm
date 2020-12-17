#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ll long long
#define V(T) vector<T>
#define VP(T) vector<pair<T, T> >
#define P(T) pair<T, T>
#define PQ(T) priority_queue<T>

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s, type="", v="";
    getline(cin, s);
    int i=0;
    for(; i<s.size(); i++) {
        if(s[i] != ' ') {
            type += s[i];
            continue;
        }
        break;
    }
    V(string) arr;
    for(i++; i<s.size(); i++) {
        if(s[i] != ' ') {
            if(s[i] == ',') continue;
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) v += s[i];
            else {
                if(s[i] == '[') {
                    arr.pb("[]");
                    i++;
                } else {
                    string v1="";
                    v1 += s[i];
                    arr.pb(v1);
                }
            }
        } else {
            cout << type;
            for(int i=arr.size()-1; i>=0; i--) cout << arr[i];
            cout << ' ' << v << ';' << '\n';
            arr.clear();
            v.clear();
        }
    }
    cout << type;
    for(int i=arr.size()-2; i>=0; i--) cout << arr[i];
    cout << ' ' << v << ';' << '\n';

    return 0;
}