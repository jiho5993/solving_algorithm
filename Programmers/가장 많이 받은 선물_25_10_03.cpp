#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

struct Info {
    int get = 0;
    int give = 0;

    int get_idx() {
        return get - give;
    }
};

unordered_map<string, Info> m;
unordered_map<string, int> cnt, res;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for (string g: gifts) {
        string name1 = "", name2 = "";
        int i=0;
        for (; i<g.size(); i++) {
            if (g[i] == ' ') break;
            name1 += g[i];
        }
        i++;
        for (; i<g.size(); i++) {
            name2 += g[i];
        }

        cnt[g]++;

        Info info1 = m[name1];
        m[name1] = {info1.get+1, info1.give};

        Info info2 = m[name2];
        m[name2] = {info2.get, info2.give+1};
    }


    for (int i=0; i<friends.size(); i++) {
        string n = friends[i];
        for (int j=i+1; j<friends.size(); j++) {
            string cur = friends[j];

            string n1 = n+" "+cur;
            string n2 = cur+" "+n;

            if (cnt[n1] > cnt[n2]) {
                res[n]++;
            } else if (cnt[n1] < cnt[n2]) {
                res[cur]++;
            } else {
                int n1_idx = m[n].get_idx();
                int n2_idx = m[cur].get_idx();

                if (n1_idx > n2_idx) res[n]++;
                else if (n1_idx < n2_idx) res[cur]++;
                else continue;
            }
        }
    }

    for (auto i: res) answer = max(answer, i.second);

    return answer;
}
