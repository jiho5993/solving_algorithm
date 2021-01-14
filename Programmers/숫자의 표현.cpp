#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i=1; i<=n; i++) {
        int tmp = 0;
        for(int j=i; tmp<=n; j++) {
            if(tmp == n) answer++;
            tmp += j;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution(10000);
    cout << res;

    return 0;
}