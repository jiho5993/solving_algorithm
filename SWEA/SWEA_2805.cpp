#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[50][50];

int foo(int n) {
    bool flag = false;
    int rs = 0, cnt = n / 2;
    fr(i, 0, n) {
        fr(j, cnt, n - cnt) {
            rs += arr[i][j];
        }
        if (!flag) cnt--;
        if (flag) cnt++;
        if (!cnt) flag = true;
    }
    return rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    fr(tc, 1, t + 1) {
        int n;
        cin >> n;
        fr(i, 0, n) {
            string s;
            cin >> s;
            fr(j, 0, n) arr[i][j] = s[j] - '0';
        }
        cout << '#' << tc << ' ' << foo(n) << '\n';
    }

    return 0;
}