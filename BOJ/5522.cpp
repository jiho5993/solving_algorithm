#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int sum=0, a, t=5;
    while(t--) {
        cin >> a;
        sum += a;
    } printf("%d", sum);

    return 0;
}