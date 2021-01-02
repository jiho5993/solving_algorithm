#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int cnt=1, p=0;
    map<string, bool> m;
    m[words[0]] = true;
    for(int i=1; i<words.size(); i++) {
        if(i%n == 0) cnt++;
        if(words[i-1][words[i-1].size()-1] != words[i][0] || m[words[i]]) {
            p = i%n + 1;
            break;
        }
        m[words[i]] = true;
    }
    if(!p) cnt = 0;
    answer = {p, cnt};

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution(2, {"hello", "one", "even", "never", "now", "world", "draw"});
    cout << res[0] << ' ' << res[1] << '\n';

    return 0;
}