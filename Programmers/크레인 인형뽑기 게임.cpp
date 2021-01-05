#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int sz=board.size();
    map<int, int> m;
    for(int i=0; i<sz; i++) {
        for(int j=0; j<sz; j++) {
            if(board[j][i] != 0) {
                m[i] = j;
                break;
            }
        }
    }

    stack<int> st;
    for(auto i:moves) {
        if(m[i-1] == sz) continue;
        int cur = board[m[i-1]][i-1];
        if(cur == 0) continue;
        m[i-1]++;
        if(st.empty()) st.push(cur);
        else {
            if(st.top() == cur) {
                answer+=2;
                st.pop();
            } else st.push(cur);
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({{0,0,0,0,0},
                         {0,0,1,0,3},
                         {0,2,5,0,1},
                         {4,2,4,4,2},
                         {3,5,1,3,1}}, {1,5,3,5,1,2,1,4});
    cout << res;

    return 0;
}