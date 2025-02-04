#include <bits/stdc++.h>
using namespace std;

bool arr[1000001] = {true, true,};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=2; i*i<=M; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=M; j+=i) arr[j] = true;
    }

    for (int i=N; i<=M; i++) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
