#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N;

bool prime(int n) {
    if(n == 1) return false;
    for(int i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;
}

void foo(int ss) {
    if(prime(ss) && to_string(ss).size() == N) {
        cout << ss << '\n';
        return;
    }
    for(int i=1; i<=9; i++) {
        int tmp = ss*10 + i;
        if(prime(ss)) {
            ss = tmp;
            foo(ss);
            ss /= 10;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    foo(2);
    foo(3);
    foo(5);
    foo(7);

    return 0;
}