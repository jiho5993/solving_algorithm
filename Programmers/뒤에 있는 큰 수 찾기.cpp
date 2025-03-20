#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), 0);

    stack<pair<int, int> > sp;
    sp.push({numbers[0], 0});

    for (int i=1; i<numbers.size(); i++) {
        int cur = numbers[i];
        while (!sp.empty() && sp.top().first < cur) {
            int idx = sp.top().second;
            answer[idx] = cur;
            sp.pop();
        }
        sp.push({cur, i});
    }

    while (!sp.empty()) {
        answer[sp.top().second] = -1;
        sp.pop();
    }

    return answer;
}
