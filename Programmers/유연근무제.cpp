#include <bits/stdc++.h>

using namespace std;

int cal_time(int t) {
    int res = t + 10;
    if (res % 100 >= 60) {
        res += 40;
    }
    return res;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i=0; i<schedules.size(); i++) {
        int sc = schedules[i];
        int sd = startday;
        bool flag = false;

        for (int j=0; j<timelogs[i].size(); j++, sd++) {
            if (sd == 6 || sd == 7) continue;
            if (sd > 7) sd = 1;
            if (timelogs[i][j] > cal_time(sc)) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        answer++;
    }

    return answer;
}
