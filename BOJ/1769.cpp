#include <bits/stdc++.h>
using namespace std;

int cnt=0;

string foo(string s) {
    if(s.size() == 1) return s;
    cnt++;
    int sum=0;
    for(char i : s) sum += (i-'0');
    return foo(to_string(sum));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string n; cin >> n;
    string num = foo(n);
    cout << cnt << '\n';
    stoi(num)%3 ? cout << "NO" : cout << "YES";

    return 0;
}