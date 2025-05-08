#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;

    int cur_time = 0;
    for (int i=0; i<attacks.size(); i++) {
        int t = attacks[i][0], d = attacks[i][1];
        int diff_t = (t - 1) - cur_time;

        answer += (diff_t * bandage[1]) + ((diff_t / bandage[0]) * bandage[2]);

        if (answer > health) {
            answer = health;
        }

        answer -= d;

        if (answer <= 0) {
            return -1;
        }

        cur_time = t;
    }

    return answer;
}

void solve() {
    vector<int> bandage[] = {
        {5, 1, 5},
        {3, 2, 7},
        {4, 2, 7},
        {1, 1, 1},
    };
    int health[] = {
        30,
        20,
        20,
        5,
    };
    vector<vector<int> > attacks[] = {
        {{2, 10}, {9, 15}, {10, 5}, {11, 5}},
        {{1, 15}, {5, 16}, {8, 6}},
        {{1, 15}, {5, 16}, {8, 6}},
        {{1, 2}, {3, 2}},
    };

    for (int i=0; i<4; i++) {
        cout << solution(bandage[i], health[i], attacks[i]) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
