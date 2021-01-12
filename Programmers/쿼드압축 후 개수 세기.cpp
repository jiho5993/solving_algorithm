#include <bits/stdc++.h>
using namespace std;

int res[2];

void foo(vector<vector<int>> &arr, int i, int j, int k, int l) {
    int tmp = arr[i][j];
    bool flag = true;
    for(int y=i; y<k; y++) {
        if(!flag) break;
        for(int x=j; x<l; x++) {
            if(tmp != arr[y][x]) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        res[tmp]++;
        return;
    }
    int a = (i+k)/2;
    int b = (j+l)/2;
    foo(arr, i, j, a, b);
    foo(arr, a, j, k, b);
    foo(arr, i, b, a, l);
    foo(arr, a, b, k, l);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    foo(arr, 0, 0, arr.size(), arr.size());
    answer={res[0], res[1]};

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({{1,1,1,1,1,1,1,1},
                         {0,1,1,1,1,1,1,1},
                         {0,0,0,0,1,1,1,1},
                         {0,1,0,0,1,1,1,1},
                         {0,0,0,0,0,0,1,1},
                         {0,0,0,0,0,0,0,1},
                         {0,0,0,0,1,0,0,1},
                         {0,0,0,0,1,1,1,1}});
    cout << res[0] << " " << res[1];

    return 0;
}