#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> m;

    for (int i=0; i<name.size(); i++) m.insert({name[i], yearning[i]});

    for (auto cur: photo) {
        int cnt = 0;
        for (string s: cur) {
            if (m.find(s) == m.end()) continue;
            cnt += m[s];
        }
        answer.push_back(cnt);
    }

    return answer;
}
