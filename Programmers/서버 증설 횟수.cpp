#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;

    for (int i=0; i<players.size(); i++) {
        int p = players[i];
        int ns = p / m;

        while (!q.empty()) {
            if (q.front() == i) q.pop();
            else break;
        }
        
        int s = q.size();
        if (ns > s) {
            for (int j=0; j<ns-s; j++) {
                q.push(i+k);
                answer++;
            }
        }
    }

    return answer;
}
