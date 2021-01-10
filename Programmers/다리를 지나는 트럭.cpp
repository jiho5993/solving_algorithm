#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int w=0, idx=0;
    queue<int> q;
    while(1) {
        if(idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        answer++;
        int tmp = truck_weights[idx];
        if(q.size() == bridge_length) {
            w -= q.front();
            q.pop();
        }
        if(w+tmp <= weight) {
            q.push(tmp);
            w += tmp;
            idx++;
        } else q.push(0);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution(100, 100, {10,10,10,10,10,10,10,10,10,10});
    cout << res;

    return 0;
}