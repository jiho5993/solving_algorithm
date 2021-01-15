#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];

    for(int i=1; i<arr.size(); i++)
        answer = lcm(answer, arr[i]);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution({1,2,3});
    cout << res;

    return 0;
}