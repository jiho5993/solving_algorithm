#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define ll long long

int isused[1001], dup[1001];

ll solution(vector<int> weights) {
    ll answer = 0;
    int N = weights.size();

    sort(weights.begin(), weights.end());

    for (int i=0; i<N-1; i++) {
        int w1 = weights[i];

        if (isused[w1]) {
            dup[w1]++;
            answer += (isused[w1]-dup[w1]);
            continue;
        }

        int s = 0;
        for (int j=i+1; j<N; j++) {
            int w2 = weights[j];
            
            double a = (double)w1/(double)w2;

            for (auto k: {2.0/2.0, 2.0/3.0, 2.0/4.0, 3.0/4.0}) {
                if (k == a) {
                    s++;
                }
            }
        }

        isused[w1] = s;
        answer += s;
    }

    return answer;
}
