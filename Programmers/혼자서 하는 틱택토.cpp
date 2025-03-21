#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

bool is_done(vector<string> board, char target) {
    bool flag = false;

    for (int i=0; i<3; i++) {
        bool f1 = true, f2 = true;
        for (int j=0; j<3; j++) {
            if (board[i][j] != target) f1 = false;
            if (board[j][i] != target) f2 = false;
        }
        if (flag && (f1 || f2)) return false;
        if (f1 || f2) flag = true;
    }

    bool f1 = true, f2 = true;
    for (int i=0; i<3; i++) {
        if (board[i][i] != target) f1 = false;
        if (board[i][2-i] != target) f2 = false;
    }
    if (flag && (f1 || f2)) return false;
    if (f1 || f2) flag = true;

    return flag;
}

int solution(vector<string> board) {
    int answer = -1;

    int oc=0, xc=0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == 'O') oc++;
            else if (board[i][j] == 'X') xc++;
        }
    }

    if (oc < xc) return 0;
    if (oc - xc > 1) return 0;

    bool of = is_done(board, 'O');
    bool xf = is_done(board, 'X');

    if (of && oc != xc+1) return 0;
    if (xf && oc != xc) return 0;

    return 1;
}
