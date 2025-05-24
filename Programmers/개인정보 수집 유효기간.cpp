#include <string>
#include <vector>

using namespace std;

int date2day(string s) {
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));

    return y*12*28 + (m-1)*28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int ts[30] = {0,};
    
    int day = date2day(today);

    for (string s: terms) ts[s[0]-'A'] = stoi(s.substr(2));

    for (int i=0; i<privacies.size(); i++) {
        string p = privacies[i];
        int cur_day = date2day(p);
        int term = ts[p[p.size()-1]-'A'];

        cur_day += term * 28;

        if (cur_day > day) continue;

        answer.push_back(i+1);
    }

    return answer;
}
