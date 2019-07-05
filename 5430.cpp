#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t, idx_cnt; cin >> t;
    string cmd, arr, val;
    while(t--) {
        deque<int> dq;
        cin >> cmd;
        cin >> idx_cnt;
        cin >> arr;
        string tmp="";
        for(int i=0; i<arr.length(); i++) {
            if(arr[i] == '[') continue;
            else if('0' <= arr[i] && arr[i] <= '9') tmp += arr[i];
            else if(arr[i] == ',' || arr[i] == ']') {
                if(!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp="";
                }
            }
        }
        bool chk = false, re=false;
        for(int i=0; i<cmd.length(); i++) {
            if(cmd[i] == 'R') re = !re;
            else {
                if(re) { // 뒤집혀있다면?
                    if(dq.empty()) {
                        chk = 1;
                        break;
                    } else dq.pop_back();
                } else {
                    if(dq.empty()) {
                        chk = 1;
                        break;
                    } else dq.pop_front();
                }
            }
        }
        if(!chk) {
            cout << '[';
            if(!re) {
                while(!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ',';
                }
            } else {
                while(!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ',';
                }
            }
            cout << ']' << '\n';
        } else cout << "error" << '\n';
    }

    return 0;
}