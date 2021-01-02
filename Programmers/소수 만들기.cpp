#include <bits/stdc++.h>
using namespace std;

int s=0;
bool p[50001];

void eratos() {
    p[1] = true;
    for(int i=2; i*i<=50001; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=50001; j+=i) p[j] = true;
    }
}

void foo(vector<int> nums, int tmp, int cnt, int idx) {
    if(cnt == 3) {
        if(!p[tmp]) s++;
        return;
    }

    if(idx != nums.size()) {
        foo(nums, tmp+nums[idx], cnt+1, idx+1);
        foo(nums, tmp, cnt, idx+1);
    }
}

int solution(vector<int> nums) {
    eratos();
    foo(nums, 0, 0, 0);

    return s;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({1, 2, 3, 4});
    cout << res << '\n';

    return 0;
} 