#include <bits/stdc++.h>
using namespace std;

string dec2N(int n, int d) {
    string ret = "";
    char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(d/n != 0) {
        ret = arr[d%n] + ret;
        d /= n;
    }
    ret = arr[d%n] + ret;
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string tmp="";
    for(int i=0; i<=t*m; i++) tmp += dec2N(n, i);
    for(int i=0; i<tmp.size() && answer.size() != t; i++) {
        if(p-1 == i) {
            p += m;
            answer += tmp[i];
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution(16, 16, 2, 2);
    cout << res;

    return 0;
}