#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    int sz = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if(nums.size() <= sz/2) answer = nums.size();
    else answer = sz/2;

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({3,3,3,2,2,2});
    cout << res;

    return 0;
}