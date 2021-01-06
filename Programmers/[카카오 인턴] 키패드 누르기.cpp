#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> arr[2] = {{4, 1}, {4, 3}};
    for(auto i:numbers) {
        if(i == 1 || i == 4 || i == 7) {
            answer += 'L';
            arr[0] = {i/3+1, 1};
        } else if(i == 3 || i == 6 || i == 9) {
            answer += 'R';
            arr[1] = {i/3, 3};
        } else {
            if(i == 0) i = 11;
            int y=i/3+1, x=2;
            int dist[2]={-1, -1};
            for(int j=0; j<2; j++) {
                int dfy=abs(arr[j].first-y);
                int dfx=abs(arr[j].second-x);
                dist[j] = dfy+dfx;
            }
            if(dist[0] < dist[1]) {
                answer += 'L';
                arr[0] = {y, x};
            } else if(dist[0] > dist[1]) {
                answer += 'R';
                arr[1] = {y, x};
            } else {
                if(hand[0] == 'l') {
                    answer += 'L';
                    arr[0] = {y, x};
                } else {
                    answer += 'R';
                    arr[1] = {y, x};
                }
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5},
                        "right");
    cout << res;

    return 0;
}