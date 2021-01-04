#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(auto i:s) {
        if(i == ' ') answer += ' ';
        else {
            if(i + n > 'z' || (i <= 'Z' && i + n > 'Z'))
                answer += i+n-26;
            else answer += i+n;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution("a B z", 4);
    cout << res;

    return 0;
}