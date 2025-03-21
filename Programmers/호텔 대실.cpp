#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define pii pair<int, int>

vector<pii> arr;

int t2i(string s) {
    string t1 = "", t2 = "";
    t1 += s[0];
    t1 += s[1];
    t2 += s[3];
    t2 += s[4];
    return stoi(t1)*100 + stoi(t2);
}

int sum_t(int t) {
    int res = t + 10;
    if (res % 100 >= 60) {
        if (res / 100 == 23) res = (res % 100) - 60;
        else res += 40;
    }
    return res;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    for (auto i: book_time) {
        arr.push_back({t2i(i[1]), t2i(i[0])});
    }

    sort(arr.begin(), arr.end(), [](pii a, pii b) {
        return a.second < b.second;
    });

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (auto i: arr) {
        answer = max(answer, (int)pq.size());
        int t1 = i.second, t2 = i.first;

        if (!pq.empty()) {
            if (sum_t(pq.top().first) <= t1) {
                pq.pop();
            }
        }
        pq.push(i);
    }


    return max(answer, (int)pq.size());
}
