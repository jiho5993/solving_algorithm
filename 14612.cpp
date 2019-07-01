#include <bits/stdc++.h>
using namespace std;

int n, m, t, tn;
string cmd;
vector<pair<int, int> > cmd_arr;

void cmd_print() {
    for(int i=0; i<cmd_arr.size(); i++)
        printf("%d ", cmd_arr[i].second);
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m;
    while(n--) {
        cin >> cmd;
        if(cmd == "order") {
            cin >> tn >> t;
            cmd_arr.push_back(make_pair(t, tn));
        } else if(cmd == "sort") {
            sort(cmd_arr.begin(), cmd_arr.end());
        } else {
            cin >> tn;
            for(int i=0; i<cmd_arr.size(); i++) {
                if(cmd_arr[i].second == tn) {
                    cmd_arr.erase(cmd_arr.begin()+i);
                    break;
                }
            }
        }
        if(cmd_arr.empty()) printf("sleep\n");
        else cmd_print();
    }

    return 0;
}