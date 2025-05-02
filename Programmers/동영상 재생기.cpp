#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int convert_time(string t) {
    string res = "";
    res += t[0];
    res += t[1];
    res += t[3];
    res += t[4];
    return stoi(res);
}

int cal_time(int t, int v, int video_len) {
    int res = t + v;

    if (v > 0) {
        if (res % 100 >= 60) res += 40;
        if (video_len < res) res = video_len;
    } else {
        if (res % 100 >= 60) res -= 40;
        if (res < 0) res = 0;
    }
    
    return res;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int v = convert_time(video_len);
    int p = convert_time(pos);
    int os = convert_time(op_start), oe = convert_time(op_end);

    for (string c: commands) {
        if (os <= p && p <= oe) p = oe;

        if (c == "prev") p = cal_time(p, -10, v);
        else p = cal_time(p, 10, v);
    }

    if (os <= p && p <= oe) p = oe;

    string res = to_string(p);
    while (res.size() < 4) {
        res = "0" + res;
    }

    answer += res[0];
    answer += res[1];
    answer += ":";
    answer += res[2];
    answer += res[3];

    return answer;
}
