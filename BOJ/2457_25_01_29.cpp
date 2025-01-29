#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr[i] = {a*100 + b, c*100 + d};
    }

    sort(arr, arr + N);

    int e = 301;
    if (arr[0].first > e) {
        cout << 0;
        return 0;
    }

    int res = 0, i = 0;
    while (e <= 1130) {
        int cur = 0;

        for (; i<N; i++) {
            if (arr[i].first <= e) {
                if (cur < arr[i].second) {
                    cur = arr[i].second;
                }
            } else {
                break;
            }
        }

        if (cur == 0) {
            cout << 0;
            return 0;
        } else {
            res++;
            e = cur;
        }
    }

    cout <<res;
 
    return 0;
}
