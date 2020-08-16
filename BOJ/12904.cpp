#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

string S, T;

bool foo() {
    while(1) {
        if(S == T) return 1;
        if(S.size() > T.size()) break;
        char tmp = T[T.size()-1];
        T.pop_back();
        if(tmp == 'B')
            reverse(all(T));
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> S >> T;
    cout << foo();

    return 0;
}